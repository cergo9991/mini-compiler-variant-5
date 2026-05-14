; ModuleID = 'mini_module'
source_filename = "mini_module"
target triple = "mipsel-unknown-linux-gnu"

define i64 @compiled_fn(i64 %arg) {
entry:
  %x = alloca i64, align 8
  %arg1 = alloca i64, align 8
  store i64 %arg, i64* %arg1, align 4
  store i64 1, i64* %x, align 4
  br label %do.body

do.body:                                          ; preds = %do.cond, %entry
  %x2 = load i64, i64* %x, align 4
  %multmp = mul i64 %x2, 2
  store i64 %multmp, i64* %x, align 4
  br label %do.cond

do.cond:                                          ; preds = %do.body
  %x3 = load i64, i64* %x, align 4
  %arg4 = load i64, i64* %arg1, align 4
  %lttmp = icmp slt i64 %x3, %arg4
  br i1 %lttmp, label %do.body, label %do.end

do.end:                                           ; preds = %do.cond
  %x5 = load i64, i64* %x, align 4
  ret i64 %x5
}
