////////////////////////////////////////////////////////////////////////////////
// File: amsterdam_method.c                                                   //
// Routines:                                                                  //
//    double Amsterdam_Method                                                 //
////////////////////////////////////////////////////////////////////////////////

#include <math.h>                                    // required for fabs()

////////////////////////////////////////////////////////////////////////////////
//  double Amsterdam_Method( double (*f)(double), double a, double c,         //
//                           double tolerance, int max_iterations, int *err)  //
//                                                                            //
//  Description:                                                              //
//     Estimate the root (zero) of f(x) using the Amsterdam method where      //
//     'a' and 'c' are initial estimates which bracket the root i.e. either   //
//     f(a) > 0 and f(c) < 0 or f(a) < 0 and f(c) > 0.  The iteration         //
//     terminates when the zero is constrained to be within an interval of    //
//     length < 'tolerance', in which case the value returned is the best     //
//     estimate that interval.                                                //
//                                                                            //
//     The Amsterdam method is an extension of Mueller's successive bisection //
//     and inverse quadratic interpolation.  Later extended by Van Wijnaarden,//
//     Dekker and still later by Brent.  Initially, the method uses the two   //
//     bracketing endpoints and the midpoint to estimate an inverse quadratic //
//     to interpolate for the root.  The interval is successively reduced by  //
//     keeping endpoints which bracket the root and an interior point used    //
//     to estimate a quadratic.  If the interior point becomes too close to   //
//     an endpoint and the function has the same sign at both points, the     //
//     interior point is chosen by the bisection method.  If inverse          //
//     quadratic interpolation is not feasible, the new interior point is     //
//     chosen by bisection, and if inverse quadratic interpolation results    //
//     in a point exterior to the bracketing interval, the new interior point //
//     is again chosen by bisection.                                          //
//                                                                            //
//  Arguments:                                                                //
//     double *f         Pointer to function of a single variable of type     //
//                       double.                                              //
//     double  a         Initial estimate.                                    //
//     double  c         Initial estimate.                                    //
//     double  tolerance Desired accuracy of the zero.                        //
//     int     max_iterations The maximum allowable number of iterations.     //
//     int     *err      0 if successful, -1 if not, i.e. if f(a)*f(b) > 0,   //
//                       -2 if the number of iterations > max_iterations.     //
//                                                                            //
//  Return Values:                                                            //
//     A zero contained within the interval (a,b).                            //
//                                                                            //
//  Example:                                                                  //
//     {                                                                      //
//        double f(double), zero, a, c, tolerance = 1.e-6;                    //
//        int err, max_iterations = 20;                                       //
//                                                                            //
//        (determine lower bound, a and upper bound, c of a zero)             //
//        zero = Amsterdam_Method( f, a, c, tolerance, max_iterations, &err); //
//        ...                                                                 //
//     }                                                                      //
//     double f(double x) { define f }                                        //
////////////////////////////////////////////////////////////////////////////////
//                                                                            //
#define NUMERATOR(dab,dcb,fa,fb,fc) fb*(dab*fc*(fc-fb)-fa*dcb*(fa-fb))
#define DENOMINATOR(fa,fb,fc) (fc-fb)*(fa-fb)*(fa-fc)

double Amsterdam_Method( double (*f)(double), double a, double c, 
                              double tolerance, int max_iterations, int *err) {

   double fa = (*f)(a), b = 0.5 * ( a + c ), fc = (*f)(c), fb = fa * fc;
   double delta, dab, dcb;
   int i;

      // If the initial estimates do not bracket a root, set the err flag and //
      // return.  If an initial estimate is a root, then return the root.     //
   
   *err = 0;
   if ( fb >= 0.0 )
      if ( fb > 0.0 )  { *err = -1; return 0.0; }
      else return ( fa == 0.0 ) ? a : c;
   
      // Insure that the initial estimate a < c. //

   if ( a > c ) {
      delta = a; a = c; c = delta; delta = fa; fa = fc; fc = delta;
   }

      // If the function at the left endpoint is positive, and the function //
      // at the right endpoint is negative.  Iterate reducing the length    //
      // of the interval by either bisection or quadratic inverse           //
      // interpolation.  Note that the function at the left endpoint        //
      // remains nonnegative and the function at the right endpoint remains //
      // nonpositive.                                                       //

   if ( fa > 0.0 ) 
      for ( i = 0; i < max_iterations; i++) {

            // Are the two endpoints within the user specified tolerance ?

         if ( ( c - a ) < tolerance ) return 0.5 * ( a + c);

            // No, Continue iteration.

         fb = (*f)(b);
 
            // Check that we are converging or that we have converged near //
            // the left endpoint of the inverval.  If it appears that the  //
            // interval is not decreasing fast enough, use bisection.      //
         if ( ( c - a ) < tolerance ) return 0.5 * ( a + c);
         if ( ( b - a ) < tolerance ) 
            if ( fb > 0 ) {
               a = b; fa = fb; b = 0.5 * ( a + c ); continue;
            }
            else return b;

            // Check that we are converging or that we have converged near //
            // the right endpoint of the inverval.  If it appears that the //
            // interval is not decreasing fast enough, use bisection.      //

         if ( ( c - b ) < tolerance )
            if ( fb < 0 ) {
               c = b; fc = fb; b = 0.5 * ( a + c ); continue;
            }
            else return b;

            // If quadratic inverse interpolation is feasible, try it. //
 
         if (  ( fa > fb ) && ( fb > fc ) ) {
            delta = DENOMINATOR(fa,fb,fc);
            if ( delta != 0.0 ) {
               dab = a - b;
               dcb = c - b;
               delta = NUMERATOR(dab,dcb,fa,fb,fc) / delta;

                  // Will the new estimate of the root be within the   //
                  // interval?  If yes, use it and update interval.    //
                  // If no, use the bisection method.                  //

               if ( delta > dab && delta < dcb ) {
                  if ( fb > 0.0 ) { a = b; fa = fb; }
                  else if ( fb < 0.0 )  { c = b; fc = fb; } 
                     else return b;
                   b += delta;
                   continue;
               }
            }   
         }

            // If not, use the bisection method. //

         fb > 0 ? ( a = b, fa = fb ) : ( c = b, fc = fb );
         b = 0.5 * ( a + c );
      }
   else 

      // If the function at the left endpoint is negative, and the function //
      // at the right endpoint is positive.  Iterate reducing the length    //
      // of the interval by either bisection or quadratic inverse           //
      // interpolation.  Note that the function at the left endpoint        //
      // remains nonpositive and the function at the right endpoint remains //
      // nonnegative.                                                       //

      for ( i = 0; i < max_iterations; i++) {

         if ( ( c - a ) < tolerance ) return 0.5 * ( a + c);
         
         fb = (*f)(b);

         if ( ( b - a ) < tolerance ) 
            if ( fb < 0 ) {
               a = b; fa = fb; b = 0.5 * ( a + c ); continue;
            }
            else return b;

         if ( ( c - b ) < tolerance )
            if ( fb > 0 ) {
               c = b; fc = fb; b = 0.5 * ( a + c ); continue;
            }
            else return b;

         if (  ( fa < fb ) && ( fb < fc ) ) {
            delta = DENOMINATOR(fa,fb,fc);
            if ( delta != 0.0 ) {
               dab = a - b;
               dcb = c - b;
               delta = NUMERATOR(dab,dcb,fa,fb,fc) / delta;
               if ( delta > dab && delta < dcb ) {
                  if ( fb < 0.0 ) { a = b; fa = fb; }
                  else if ( fb > 0.0 )  { c = b; fc = fb; } 
                     else return b;
                   b += delta;
                   continue;
               }
            }   
         }
         fb < 0 ? ( a = b, fa = fb ) : ( c = b, fc = fb );
         b = 0.5 * ( a + c );
      }
   *err = -2;
   return  b;
}
