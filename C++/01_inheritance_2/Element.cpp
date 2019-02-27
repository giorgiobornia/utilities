#include <iostream>
#include "Element.hpp"

using namespace std;

void Element::print() const {
  cout << _n_nodes << endl;
  cout << d1 << endl;
return;
}

 Element::Element(int myint,double mydouble){
  set_N_Nodes(myint);
  set_double(mydouble);
  
}

void Element::set_N_Nodes(int int_in){
 _n_nodes= int_in;
  
  return ;
}

void Element::set_double(double double_in){
 d1= double_in;
  
  return ;
}

int Element::get_N_Nodes()  const {
  return _n_nodes;
}  


void Element::show_id()const{
  
  cout<<"I am Element" <<std::endl ; 
  
}