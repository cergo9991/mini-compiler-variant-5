; ModuleID = 'mini_module'
source_filename = "mini_module"
target triple = "mipsel-unknown-linux-gnu"

define double @scale(double %value, double %factor) {
entry:
  %factor2 = alloca double, align 8
  %value1 = alloca double, align 8
  store double %value, double* %value1, align 8
  store double %factor, double* %factor2, align 8
  %value3 = load double, double* %value1, align 8
  %factor4 = load double, double* %factor2, align 8
  %fmultmp = fmul double %value3, %factor4
  ret double %fmultmp
}

define i64 @compiled_fn(i64 %arg) {
entry:
  %x = alloca double, align 8
  %arg1 = alloca i64, align 8
  store i64 %arg, i64* %arg1, align 4
  %scale.call = call double @scale(double 8.000000e+00, double 5.000000e-01)
  store double %scale.call, double* %x, align 8
  br label %do.body

do.body:                                          ; preds = %do.cond, %entry
  %x2 = load double, double* %x, align 8
  %faddtmp = fadd double %x2, 2.500000e-01
  store double %faddtmp, double* %x, align 8
  br label %do.cond

do.cond:                                          ; preds = %do.body
  %x3 = load double, double* %x, align 8
  %flttmp = fcmp olt double %x3, 5.000000e+00
  br i1 %flttmp, label %do.body, label %do.end

do.end:                                           ; preds = %do.cond
  %x4 = load double, double* %x, align 8
  %feqtmp = fcmp oeq double %x4, 5.000000e+00
  br i1 %feqtmp, label %if.then, label %if.end

if.then:                                          ; preds = %do.end
  %arg5 = load i64, i64* %arg1, align 4
  %addtmp = add i64 %arg5, 2
  ret i64 %addtmp

if.end:                                           ; preds = %do.end
  ret i64 0
}
