#ifndef _Element_hpp_
#define _Element_hpp_


 class Element {
   
 public:
   
  Element(int,double);

  ~Element(){};
  
  void print() const;
  int get_N_Nodes() const;

  void set_N_Nodes(int myint);
  void set_double(double);
 
 virtual void show_id() const;
  
  
 private:
   int _n_nodes;
   double d1;
   bool b1;
  };
  
  
  
  #endif