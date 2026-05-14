; ModuleID = 'mini_module'
source_filename = "mini_module"
target triple = "mipsel-unknown-linux-gnu"

define i64 @compiled_fn(i64 %arg) {
entry:
  %arg1 = alloca i64, align 8
  store i64 %arg, i64* %arg1, align 4
  %arg2 = load i64, i64* %arg1, align 4
  %gttmp = icmp sgt i64 %arg2, 10
  br i1 %gttmp, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  %arg3 = load i64, i64* %arg1, align 4
  ret i64 %arg3

if.else:                                          ; preds = %entry
  %arg4 = load i64, i64* %arg1, align 4
  %addtmp = add i64 %arg4, 1
  ret i64 %addtmp

if.end:                                           ; No predecessors!
  ret i64 0
}
