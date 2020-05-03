#include <math.h>


   struct  func_data {
       
   double  (* func)(const  double );     
   double  (* func_der)(const  double );     

   double newt_x_old;
   
   double sec_x_old;
   double sec_x_oldold;
   
   };

   
//===========   
  double  f0(const double x )       {  return  x*x - x;  }
  double  f0_der(const double x )   {   return 2. * x - 1.;  }

  const double f0_newt_x_old = 0.4;
  const double f0_sec_x_old = 0.4;
  const double f0_sec_x_oldold = 0.3;

//===========   
  double  f1(const double x )       {  return  x*x;  }
