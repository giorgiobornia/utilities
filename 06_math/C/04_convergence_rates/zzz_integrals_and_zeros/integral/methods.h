/*rettangoli punto medio*/
#if MYMETHOD == 0
  #define METHODFILE "rectangle_midpoint.out"
#endif
/*rettangoli estremo inferiore*/
#if MYMETHOD == 1
  #define METHODFILE "rectangle_lower_end.out"
#endif
/*rettangoli estremo superiore*/
#if MYMETHOD == 2
  #define METHODFILE "rectangle_upper_end.out"
#endif
/*trapezi*/
#if MYMETHOD == 3
  #define METHODFILE "trapezoid.out"
#endif
/*trapezi con correzione finale*/
#if MYMETHOD == 4
  #define METHODFILE "trapezoid_corrected.out"
#endif
/*Simpson*/
#if MYMETHOD == 5
  #define METHODFILE "simpson.out"
#endif
