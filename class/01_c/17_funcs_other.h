#include <math.h>


   struct  func_data {
       
   double  (* func)(const  double );     
   double  (* func_der)(const  double );     
//    double  (* func_antider)(const  double );     

//    double fp_x_old;
//    
//    double bis_a0;
//    double bis_b0;
   
   double newt_x_old;
   
   double sec_x_old;
   double sec_x_oldold;
   
//    double chord_x_old;
//    double chord_a0;
//    double chord_b0;
   
   };

   
//===========   
  double  f0(const double x )       {  return  x*x - x;  }
  double  f0_der(const double x )   {   return 2. * x - 1.;  }
//   double  f0_antider(const double x )   {   return x * x * x /3. - 0.5 * x * x;  }

  const double f0_fp_x_old = 0.8;
  const double f0_newt_x_old = 0.8;
  const double f0_sec_x_old = 0.8;
  const double f0_sec_x_oldold = 0.3;
  const double f0_bis_a0 = -0.4;
  const double f0_bis_b0 =  0.9;
  

//===========   
  double  f1(const double x )       {  return  cos(x) - x;  }
  double  f1_der(const double x )   {   return - sin(x) - 1.;  }
//   double  f1_antider(const double x )   {   return  sin(x)  - 0.5 * x * x;  }
  
  const double f1_newt_x_old = 0.3;
  const double f1_sec_x_old = 0.8;
  const double f1_sec_x_oldold = 0.3;

  
//===========   
  double  f2(const double x )       {  return  0.5 * cos(x) - x;  }
  double  f2_der(const double x )   {   return - 0.5 * sin(x) - 1.;  }
//   double  f2_antider(const double x )   {   return  0.5 * sin(x)  - 0.5 * x * x;  }
  
  const double f2_newt_x_old = 0.3;
  const double f2_sec_x_old = 0.8;
  const double f2_sec_x_oldold = 0.3;

//===========
  double  f3(const double x )       {  return         0.75 * exp(-x) - x;  }
  double  f3_der(const double x )   {   return      - 0.75 * exp(-x) - 1.;  }
//   double  f3_antider(const double x )   {   return  + 0.75 * exp(-x) - 0.5 * x * x;  }
  
  const double f3_newt_x_old = 0.3;
  const double f3_sec_x_old = 0.8;
  const double f3_sec_x_oldold = 0.3;

//===========
  double  f4(const double x )       {  return  - log(x) - x;  }
  double  f4_der(const double x )   {   return - 1./x  - 1.;  }
//   double  f4_antider(const double x )   {   return - x * log(x) + x  - 0.5 * x * x;  }
  
  const double f4_newt_x_old = 0.3;
  const double f4_sec_x_old = 0.8;
  const double f4_sec_x_oldold = 0.3;

//===========
  double  f5(const double x )       {  return  0.2 * (x*x + 6.) - x;  }
  double  f5_der(const double x )   {   return 0.4 * x - 1.;  }
//   double  f5_antider(const double x )   {   return ;  }
  
  const double f5_newt_x_old = 0.3;
  const double f5_sec_x_old = 0.8;
  const double f5_sec_x_oldold = 0.3;
 
  
//===========
  double  f6(const double x )       {  return  (x*x + 4.)/(2. * x) - x;  }  //quadratic fp
  double  f6_der(const double x )   {   return 0.5 + 2. * log(x);  }
//   double  f6_antider(const double x )   {   return ;  }
  
  const double f6_fp_x_old = 0.3;
  const double f6_newt_x_old = 0.3;
  const double f6_sec_x_old = 0.8;
  const double f6_sec_x_oldold = 0.3;
  
//===========
  double  f7(const double x )       {  return  0.25 * x * x;  }  //linear Newton
  double  f7_der(const double x )   {   return 0.5 * x;  }
//   double  f7_antider(const double x )   {   return 0.25 * x * x * x /3.;  }
  
  const double f7_newt_x_old = 0.3;
  const double f7_sec_x_old = 0.8;
  const double f7_sec_x_oldold = 0.3;  
