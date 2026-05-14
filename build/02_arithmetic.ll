; ModuleID = 'mini_module'
source_filename = "mini_module"
target triple = "mipsel-unknown-linux-gnu"

define i64 @compiled_fn(i64 %arg) {
entry:
  %y = alloca i64, align 8
  %x = alloca i64, align 8
  %arg1 = alloca i64, align 8
  store i64 %arg, i64* %arg1, align 4
  %arg2 = load i64, i64* %arg1, align 4
  %addtmp = add i64 %arg2, 2
  store i64 %addtmp, i64* %x, align 4
  %x3 = load i64, i64* %x, align 4
  %multmp = mul i64 %x3, 3
  %subtmp = sub i64 %multmp, 2
  %addtmp4 = add i64 %subtmp, 1
  store i64 %addtmp4, i64* %y, align 4
  %y5 = load i64, i64* %y, align 4
  ret i64 %y5
}
