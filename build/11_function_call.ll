; ModuleID = 'mini_module'
source_filename = "mini_module"
target triple = "mipsel-unknown-linux-gnu"

define i64 @add(i64 %a, i64 %b) {
entry:
  %b2 = alloca i64, align 8
  %a1 = alloca i64, align 8
  store i64 %a, i64* %a1, align 4
  store i64 %b, i64* %b2, align 4
  %a3 = load i64, i64* %a1, align 4
  %b4 = load i64, i64* %b2, align 4
  %addtmp = add i64 %a3, %b4
  ret i64 %addtmp
}

define i64 @compiled_fn(i64 %arg) {
entry:
  %arg1 = alloca i64, align 8
  store i64 %arg, i64* %arg1, align 4
  %arg2 = load i64, i64* %arg1, align 4
  %add.call = call i64 @add(i64 %arg2, i64 5)
  ret i64 %add.call
}
