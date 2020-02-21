#ifndef _Face_hpp_
#define _face_hpp_
#include "Element.hpp"
class Face: public Element{
  
public:
  Face(int myint,double mydouble);
  
  virtual void show_id() const;
   
  
   
};
 #endif