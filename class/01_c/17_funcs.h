#include <math.h>


   struct  func_data {
       
   double  (* func)(const  double );     
   double  (* func_der)(const  double );     
   double  (* func_antider)(const  double );     

   double newt_x_old;
   
   double sec_x_old;
   double sec_x_oldold;
   
   };

   
//===========   
  double  f0(const double x )       {  return  x * x - x;  }
  double  f0_der(const double x )   {   return 2. * x - 1.;  }

  const double f0_newt_x_old = 0.4;
  const double f0_sec_x_old = 0.4;
  const double f0_sec_x_oldold = 0.3;

//===========   
  double  f1(const double x )       {  return  cos( x);  }
  double  f1_antider(const double x )       {  return   sin( x);  }
//   double  f1(const double x )       {  return  x*x*x*x*x;  }
//   double  f1_antider(const double x )       {  return   x * x * x * x * x * x / 6.;  }

  
// //=====================
// //=== Ex functions ========   
// //====================
// //===========   
//   double  func1(const double x )       {  return  4. * sin(x) + 1. - x;  }
//   double  func1_antider(const double x )       {  return - 4. * cos(x) + x - 0.5 * x * x ;  }
// 
// //===========   
//   double  func2(const double x )       {  return  exp(-x) - x - 5.;  }
//   double  func2_antider(const double x )       {  return - ( exp(-x) + 0.5 * x * x + 5. * x );  }
// 
// //===========   
//   double  func3(const double x )       {  return  (x + 1) * exp ( x/4.) - 2;  }
//   double  func3_antider(const double x )       {  return 4 (x - 3) \cdot \exp \left( \frac{x}{4} \right) - 2 x;  }
// 
// //===========   
//   double  func4(const double x )       {  return  x^4/4 - 2 * x^3 + x^2 - 5 * x + 8;  }
//   double  func4_antider(const double x )       {  return \frac{x^5}{20} - \frac{x^4}{2} + \frac{x^3}{3} - 5 \frac{x^2}{2} + 8 \, x;  }
//   
// //===========   
//   double  func5(const double x )       {  return    3 * cos(x) + 2 - x^2/2;  }
//   double  func5_antider(const double x )       {  return  3 \, \sin(x) + 2 \, x - \frac{x^3}{6};  }
//   
// //===========   
//   double  func6(const double x )       {  return  exp(x) - x^2 + x;  }
//   double  func6_antider(const double x )       {  return \exp(x) - \frac{x^3}{3} + \frac{x^2}{2};  }
// 
// //===========   
//   double  func7(const double x )       {  return   x^2 + 8 * sin ( 3 * x/4 ) + x - 5 ;  }
//   double  func7_antider(const double x )       {  return  \frac{x^3}{3} - \frac{32}{3} \cos \left( \frac{3}{4} x \right) + \frac{x^2}{2} - 5 \, x ;  }
// 
// //===========   
//   double  func8(const double x )       {  return  x^3 - x^2/2 + 2 * x + 1 + exp(x);  }
//   double  func8_antider(const double x )       {  return \frac{x^4}{4} - \frac{x^3}{6} + x^2 + x  + \exp(x);  }
//   
// //===========   
//   double  func9(const double x )       {  return  ;  }                exp ( x/3 ) + 4 * sin ( x/2 ) - 2 + x }
//   double  func9_antider(const double x )       {  return ;  }          3 \,\exp(\frac{x}{3}) - 8 \, \cos \left( \frac{x}{2} \right) - 2 \,x + \frac{x^2}{2} }
//   
// //===========   
//   double  func10(const double x )       {  return  ;  }            x^3 - 2 * cos(x) - x - 20 }
//   double  func10_antider(const double x )       {  return ;  }     \frac{x^4}{4} - 2 \, \sin(x) - \frac{x^2}{2} - 20 \, x }
// 
// //===========   
//   double  func11(const double x )       {  return  ;  }         3 * x * exp ( - x/4 ) - cos(x) }
//   double  func11_antider(const double x )       {  return ;  }  -12 \, (4 + x) \, \exp \left(- \frac{x}{4} \right) - \, \sin(x) }
// 
// //===========   
//   double  func12(const double x )       {  return  ;  }          3 * x^3  - 4 * cos ( 3/2 * x ) -1 }
//   double  func12_antider(const double x )       {  return ;  }    \frac{3}{4} \,x^4 - \frac{8}{3} \, \sin \left( \frac{3}{2} x \right) - x }
//   
  
