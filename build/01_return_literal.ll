; ModuleID = 'mini_module'
source_filename = "mini_module"
target triple = "mipsel-unknown-linux-gnu"

define i64 @compiled_fn(i64 %arg) {
entry:
  %arg1 = alloca i64, align 8
  store i64 %arg, i64* %arg1, align 4
  ret i64 42
}
