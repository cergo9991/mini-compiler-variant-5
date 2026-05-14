; ModuleID = 'mini_module'
source_filename = "mini_module"
target triple = "mipsel-unknown-linux-gnu"

define i64 @compiled_fn(i64 %arg) {
entry:
  %i = alloca i64, align 8
  %sum = alloca i64, align 8
  %arg1 = alloca i64, align 8
  store i64 %arg, i64* %arg1, align 4
  store i64 0, i64* %sum, align 4
  store i64 0, i64* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.step, %entry
  %i2 = load i64, i64* %i, align 4
  %arg3 = load i64, i64* %arg1, align 4
  %lttmp = icmp slt i64 %i2, %arg3
  br i1 %lttmp, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %sum4 = load i64, i64* %sum, align 4
  %i5 = load i64, i64* %i, align 4
  %addtmp = add i64 %sum4, %i5
  store i64 %addtmp, i64* %sum, align 4
  br label %for.step

for.step:                                         ; preds = %for.body
  %i6 = load i64, i64* %i, align 4
  %addtmp7 = add i64 %i6, 1
  store i64 %addtmp7, i64* %i, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  %sum8 = load i64, i64* %sum, align 4
  ret i64 %sum8
}
