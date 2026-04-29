# Мини-компилятор, вариант 5

Курсовой проект по разработке учебного компилятора. Компилятор принимает программу на C-подобном учебном языке, строит AST, выполняет семантический анализ, генерирует LLVM IR и объектный файл для MIPS.

Вариант 5:

- конструкция варианта: `do / while`;
- архитектура: MIPS;
- стиль синтаксиса: C-style syntax;
- LLVM target triple: `mipsel-unknown-linux-gnu`.

## Возможности языка

Поддерживаются:

- тип `int`, который компилируется в LLVM `i64`;
- функции вида `int name(int arg) { ... }`;
- арифметика: `+ - * / %`;
- сравнения: `== != < <= > >=`;
- логика: `&& || !` с short-circuit;
- `if / else`;
- `for`;
- `do { ... } while (condition);`;
- `return`;
- вызовы функций.

Для совместимости с ранней версией проекта парсер также понимает форму `fn name(...) -> int`, но основной синтаксис варианта 5 - C-style.

## Структура проекта

```text
.
├── CMakeLists.txt
├── runtime/
│   └── main.c
├── src/
│   ├── ast.hpp / ast.cpp
│   ├── lexer.l
│   ├── parser.y
│   ├── sema.hpp / sema.cpp
│   ├── codegen.hpp / codegen.cpp
│   └── driver.cpp
├── tests/
│   ├── 05_do_while_sum.mc
│   ├── 06_do_while_at_least_once.mc
│   └── ...
├── tools/
│   └── scripts for report generation
└── README.md
```

## Требования для сборки

Рекомендуемая среда: Ubuntu 22.04 или WSL Ubuntu.

Нужны:

- CMake;
- C++17 compiler: `g++` или `clang++`;
- Flex;
- GNU Bison;
- LLVM 14 development packages;
- LLVM MIPS backend components.

Установка зависимостей на Ubuntu/WSL:

```bash
sudo apt update
sudo apt install -y build-essential cmake flex bison llvm-14 llvm-14-dev clang-14
```

Проверка инструментов:

```bash
cmake --version
flex --version
bison --version
llvm-config-14 --version
llvm-config-14 --components | tr ' ' '\n' | grep -E '^(mips|mipscodegen|mipsdesc|mipsinfo)$'
```

Если `cmake` не находит LLVM, укажите путь явно:

```bash
cmake -S . -B build -DLLVM_DIR=/usr/lib/llvm-14/cmake
```

## Сборка

Из корня проекта:

```bash
cmake -S . -B build
cmake --build build
```

После сборки исполняемый файл компилятора будет находиться здесь:

```text
build/mini_cc
```

## Быстрый запуск

Скомпилировать тестовую программу в MIPS object file и сохранить LLVM IR:

```bash
build/mini_cc tests/05_do_while_sum.mc \
  -o build/05_do_while_sum.o \
  --emit-ir build/05_do_while_sum.ll
```

Проверить, что объектный файл действительно MIPS:

```bash
file build/05_do_while_sum.o
```

Ожидаемый результат содержит:

```text
ELF 32-bit LSB relocatable, MIPS
```

Проверить, что в LLVM IR есть блоки цикла `do/while`:

```bash
grep -E 'target triple|do\.body|do\.cond|do\.end' build/05_do_while_sum.ll
```

Ожидаемые фрагменты:

```text
target triple = "mipsel-unknown-linux-gnu"
do.body:
do.cond:
do.end:
```

## Запуск в MIPS-эмуляторе

Для полноценного запуска MIPS object file нужны кросс-компилятор и QEMU:

```bash
sudo apt install -y gcc-mipsel-linux-gnu qemu-user
```

Сборка и запуск:

```bash
build/mini_cc tests/05_do_while_sum.mc \
  -o build/05_do_while_sum.o \
  --emit-ir build/05_do_while_sum.ll

mipsel-linux-gnu-gcc runtime/main.c build/05_do_while_sum.o \
  -o build/05_do_while_sum.mips

qemu-mipsel -L /usr/mipsel-linux-gnu build/05_do_while_sum.mips
```

Для текущего `runtime/main.c`, который вызывает `compiled_fn(10)`, тест `05_do_while_sum.mc` должен вывести:

```text
45
```

## Тесты

Позитивные тесты компиляции:

```bash
build/mini_cc tests/01_return_literal.mc -o build/01_return_literal.o --emit-ir build/01_return_literal.ll
build/mini_cc tests/02_arithmetic.mc -o build/02_arithmetic.o --emit-ir build/02_arithmetic.ll
build/mini_cc tests/03_if_else.mc -o build/03_if_else.o --emit-ir build/03_if_else.ll
build/mini_cc tests/04_for.mc -o build/04_for.o --emit-ir build/04_for.ll
build/mini_cc tests/05_do_while_sum.mc -o build/05_do_while_sum.o --emit-ir build/05_do_while_sum.ll
build/mini_cc tests/06_do_while_at_least_once.mc -o build/06_do_while_at_least_once.o --emit-ir build/06_do_while_at_least_once.ll
build/mini_cc tests/07_do_while_power.mc -o build/07_do_while_power.o --emit-ir build/07_do_while_power.ll
build/mini_cc tests/10_short_circuit.mc -o build/10_short_circuit.o --emit-ir build/10_short_circuit.ll
build/mini_cc tests/11_function_call.mc -o build/11_function_call.o --emit-ir build/11_function_call.ll
```

Негативные тесты должны завершаться `semantic error`:

```bash
build/mini_cc tests/08_type_error.mc -o build/bad_type.o
build/mini_cc tests/09_undeclared_variable.mc -o build/bad_name.o
```

Примеры ожидаемых сообщений:

```text
semantic error: line 2, column 5: initializer for variable 'x' has type bool, expected int
semantic error: line 2, column 12: use of undeclared variable 'missing'
```

## Пример программы

```c
int compiled_fn(int arg) {
    int i = 0;
    int sum = 0;

    do {
        sum = sum + i;
        i = i + 1;
    } while (i < arg);

    return sum;
}
```

## Семантика `do / while`

- тело цикла выполняется минимум один раз;
- условие проверяется после тела;
- условие должно иметь тип `bool`;
- в LLVM IR создаются блоки `do.body`, `do.cond` и `do.end`;
- переменные, объявленные внутри блока `do { ... }`, не видны после закрывающей фигурной скобки.


