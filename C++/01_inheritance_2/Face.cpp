#include <iostream>
#include "Element.hpp"
#include "Face.hpp"

using namespace std;


 
Face::Face(int myint,double mydouble) : Element(myint,mydouble)
  
{
  
}

void Face :: show_id() const {
  cout<<"I am Face" <<std::endl ;
}