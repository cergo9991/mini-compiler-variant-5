; ModuleID = 'mini_module'
source_filename = "mini_module"
target triple = "mipsel-unknown-linux-gnu"

define i64 @compiled_fn(i64 %arg) {
entry:
  %sum = alloca i64, align 8
  %i = alloca i64, align 8
  %arg1 = alloca i64, align 8
  store i64 %arg, i64* %arg1, align 4
  store i64 0, i64* %i, align 4
  store i64 0, i64* %sum, align 4
  br label %do.body

do.body:                                          ; preds = %do.cond, %entry
  %sum2 = load i64, i64* %sum, align 4
  %i3 = load i64, i64* %i, align 4
  %addtmp = add i64 %sum2, %i3
  store i64 %addtmp, i64* %sum, align 4
  %i4 = load i64, i64* %i, align 4
  %addtmp5 = add i64 %i4, 1
  store i64 %addtmp5, i64* %i, align 4
  br label %do.cond

do.cond:                                          ; preds = %do.body
  %i6 = load i64, i64* %i, align 4
  %arg7 = load i64, i64* %arg1, align 4
  %lttmp = icmp slt i64 %i6, %arg7
  br i1 %lttmp, label %do.body, label %do.end

do.end:                                           ; preds = %do.cond
  %sum8 = load i64, i64* %sum, align 4
  ret i64 %sum8
}
