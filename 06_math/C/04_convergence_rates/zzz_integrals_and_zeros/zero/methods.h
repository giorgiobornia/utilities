/***METHODS******/
#if MYMETHOD == 0
  #define METHODFILE "tangent.out"
  #define CONV_ORDER 2.
#endif
#if MYMETHOD == 1
  #define METHODFILE "secant.out"
  #define CONV_ORDER 1.618
#endif
#if MYMETHOD == 2
  #define METHODFILE "fixed_point.out"
  #define CONV_ORDER 1.
#endif
#if MYMETHOD == 3
  #define METHODFILE "bisection.out"
  #define CONV_ORDER 1.
#endif
