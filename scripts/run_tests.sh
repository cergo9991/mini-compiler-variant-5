#!/usr/bin/env bash

set -u

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "${SCRIPT_DIR}/.." && pwd)"
cd "$ROOT_DIR"

COMPILER_ARG="${1:-./build/mini_cc}"
if [[ "$COMPILER_ARG" = /* ]]; then
    COMPILER="$COMPILER_ARG"
else
    COMPILER="$ROOT_DIR/${COMPILER_ARG#./}"
fi

BUILD_DIR="$ROOT_DIR/build/test_runs"
QEMU_SYSROOT="/usr/mipsel-linux-gnu"

pass_count=0
fail_count=0

mkdir -p "$BUILD_DIR"

if [[ ! -x "$COMPILER" ]]; then
    echo "Compiler not found or not executable: $COMPILER"
    echo "Usage: bash scripts/run_tests.sh ./build/mini_cc"
    exit 1
fi

if ! command -v mipsel-linux-gnu-gcc >/dev/null 2>&1; then
    echo "Required tool not found: mipsel-linux-gnu-gcc"
    exit 1
fi

if ! command -v qemu-mipsel >/dev/null 2>&1; then
    echo "Required tool not found: qemu-mipsel"
    exit 1
fi

report_pass() {
    local category="$1"
    local name="$2"
    printf '[PASS] %-8s %s\n' "$category" "$name"
    pass_count=$((pass_count + 1))
}

report_fail() {
    local category="$1"
    local name="$2"
    local message="$3"
    local log_file="${4:-}"
    printf '[FAIL] %-8s %s\n' "$category" "$name"
    printf '        %s\n' "$message"
    if [[ -n "$log_file" && -f "$log_file" ]]; then
        while IFS= read -r line; do
            printf '        %s\n' "$line"
        done <"$log_file"
    fi
    fail_count=$((fail_count + 1))
}

run_positive_test() {
    local name="$1"
    local expected="$2"
    local src="tests/${name}.mc"
    local obj="${BUILD_DIR}/${name}.o"
    local ll="${BUILD_DIR}/${name}.ll"
    local bin="${BUILD_DIR}/${name}.mips"
    local log="${BUILD_DIR}/${name}.log"
    local output

    : >"$log"

    if ! "$COMPILER" "$src" -o "$obj" --emit-ir "$ll" >"$log" 2>&1; then
        report_fail "positive" "$name" "Compilation failed unexpectedly." "$log"
        return
    fi

    if ! mipsel-linux-gnu-gcc runtime/main.c "$obj" -o "$bin" >>"$log" 2>&1; then
        report_fail "positive" "$name" "Link step failed unexpectedly." "$log"
        return
    fi

    if ! output="$(qemu-mipsel -L "$QEMU_SYSROOT" "$bin" 2>>"$log")"; then
        report_fail "positive" "$name" "Program execution failed unexpectedly." "$log"
        return
    fi

    output="${output//$'\r'/}"
    output="${output%$'\n'}"

    if [[ "$output" == "$expected" ]]; then
        report_pass "positive" "$name"
    else
        printf '%s\n' "Expected output: $expected" >>"$log"
        printf '%s\n' "Actual output:   $output" >>"$log"
        report_fail "positive" "$name" "Program produced an unexpected result." "$log"
    fi
}

run_negative_test() {
    local category="$1"
    local name="$2"
    local expected_fragment="$3"
    local src="tests/${name}.mc"
    local obj="${BUILD_DIR}/${name}.o"
    local log="${BUILD_DIR}/${name}.log"

    : >"$log"

    if "$COMPILER" "$src" -o "$obj" >"$log" 2>&1; then
        report_fail "$category" "$name" "Compilation succeeded, but failure was expected." "$log"
        return
    fi

    if grep -Fq "$expected_fragment" "$log"; then
        report_pass "$category" "$name"
    else
        printf '%s\n' "Expected message fragment: $expected_fragment" >>"$log"
        report_fail "$category" "$name" "Compiler failed, but with an unexpected diagnostic." "$log"
    fi
}

run_positive_test "01_return_literal" "42"
run_positive_test "02_arithmetic" "35"
run_positive_test "03_if_else" "11"
run_positive_test "04_for" "45"
run_positive_test "05_do_while_sum" "45"
run_positive_test "06_do_while_at_least_once" "13"
run_positive_test "07_do_while_power" "16"
run_positive_test "10_short_circuit" "123"
run_positive_test "11_function_call" "15"
run_positive_test "12_float_arithmetic" "12"

run_negative_test "semantic" "08_type_error" "semantic error"
run_negative_test "semantic" "09_undeclared_variable" "semantic error"
run_negative_test "semantic" "13_float_type_error" "semantic error"
run_negative_test "syntax" "14_parse_missing_semicolon" "parse error"
run_negative_test "syntax" "15_parse_bad_do_while" "parse error"
run_negative_test "lexical" "16_lex_invalid_character" "unexpected invalid token"
run_negative_test "semantic" "17_missing_compiled_fn" "required function 'compiled_fn' is missing"
run_negative_test "semantic" "18_bad_compiled_signature" "compiled_fn must have signature: int compiled_fn(int arg)"

echo
echo "Total passed: $pass_count"
echo "Total failed: $fail_count"

if [[ "$fail_count" -ne 0 ]]; then
    exit 1
fi
