; ModuleID = 'mini_module'
source_filename = "mini_module"
target triple = "mipsel-unknown-linux-gnu"

define i64 @compiled_fn(i64 %arg) {
entry:
  %arg1 = alloca i64, align 8
  store i64 %arg, i64* %arg1, align 4
  %arg2 = load i64, i64* %arg1, align 4
  %lttmp = icmp slt i64 %arg2, 0
  br i1 %lttmp, label %logic.rhs, label %logic.end

logic.rhs:                                        ; preds = %entry
  br label %logic.end

logic.end:                                        ; preds = %logic.rhs, %entry
  %logictmp = phi i1 [ false, %entry ], [ poison, %logic.rhs ]
  br i1 %logictmp, label %if.then, label %if.else

if.then:                                          ; preds = %logic.end
  ret i64 1

if.else:                                          ; preds = %logic.end
  ret i64 123

if.end:                                           ; No predecessors!
  ret i64 0
}
