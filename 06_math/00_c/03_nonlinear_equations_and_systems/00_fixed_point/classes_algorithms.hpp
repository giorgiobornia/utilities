

class function_base {
    
    
public:
  
  virtual double fun(const double x) { abort(); }

  virtual double fun_der(const double x) { abort(); }

  virtual double fun_antider(const double x) { abort(); }

};



class function_0 :  public function_base {
    
  public:
    
  double fun(const double x) { return x * x - x; }

  double fun_der(const double x) { return 2. * x - 1.;  }
      
  double fun_antider(const double x) { return  x * x * x / 3. - x * x / 2.; }


}


class function_1 :  public function_base {
    
  public:
    
  double fun(const double x) { return 4.*sin(x) + 1. - x; }

  double fun_der(const double x) { return 4. * cos(x) - 1.;  }
      
  double fun_antider(const double x) { return  - 4.*cos(x) + x - x*x / 2.; }


}



class function_2 :  public function_base {
    
  public:
    
      double fun(const double x) { return  exp(-x) - x - 5.; }

  double fun_der(const double x) { return -exp(-x) - 1.;  }
      
  double fun_antider(const double x) { return  - ( exp(-x) + x*x/2. + 5.*x); }


}



class function_3 :  public function_base {
    
  public:
    
    
      double fun(const double x) { return    (x+1.)* exp(x/4.) - 2.  ; }

  double fun_der(const double x) { return     exp(x/4.)  +  (x+1.)*exp(x/4.)/4.;  }
      
  double fun_antider(const double x) { return  4.*(x-3.)*exp(x/4.) - 2.*x ; }


}


