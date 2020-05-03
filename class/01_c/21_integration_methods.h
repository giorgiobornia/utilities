
double rectangle(const double a, const double b, double  (* f)(const  double )) {
    
   double integral = 0.;
   
   integral = (b - a) * f( 0.5 * (a+b) );
   
 
  return integral;    
    
}


double trapezoid(const double a, const double b, double  (* f)(const  double )) {
    
   double integral = 0.;
   
   integral = 0.5 * (b - a) * ( f(a) + f(b) );
   
 
  return integral;    
    
}


double simpson(const double a, const double b, double  (* f)(const  double )) {
    
   double integral = 0.;
   
   integral = (b - a) / 6. * ( f(a) + 4. * f( 0.5 * (a+b) ) + f(b) );
   
 
  return integral;    
    
}


double gauss_1n(const double a, const double b, double  (* f)(const  double )) {
    
 
    return rectangle(a, b, f);
    
}


double gauss_2n(const double a, const double b, double  (* f)(const  double )) {
    
   
   double nodes_can[2];
   double weights_can[2];
   
   nodes_can[0] = - 0.5773502692;  //- sqrt(3.)/3.;
   nodes_can[1] =   0.5773502692;  //  sqrt(3.)/3.;
   
   weights_can[0] =  weights_can[1] = 1.;
   
   
   
   //mapping to canonical interval 
   
   const double h = (b - a);
   const double mp2 = a + b;
   
   //   a -> -1  b -> 1
   
   // (a,-1) (b,1)
   
   // (y - y_1)/(y_2 - y_1)  = (x - x_1)/(x_2 - x_1)
   // (y +1)/2  = (x - a)/(b - a)
   // y  = 2 * (x - a)/(b - a)  - 1 =   ( 2 x - 2 a - b + a  ) / (b - a) =  ( 2. * x -  mp2  ) * h_rec 
   // x = real coordinate, y = canonical coordinate

   // h * y  =  ( 2. * x -  mp2  )
   // 0.5 *(h * y  + mp2) =  x 
   
   double integral = 0.;
   
   for (unsigned q = 0; q < 2; q++) {
       
       integral +=  weights_can[q] *  f( 0.5 * (h * nodes_can[q]  + mp2) );
       
   }
   
   integral *=  0.5 * h;
   
   
    
   return integral;    
    
}









