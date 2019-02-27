#ifndef _Edge_hpp_
#define _Edge_hpp_

#include "Element.hpp"
#include <sstream>
#include <iostream>


class Edge: public Element {
  
  int direction;
  
public:
  Edge(int myint,double mydouble,int mydeer);
//   void set_N_Nodes(int);
  
  virtual void show_id() const;
  
 Edge operator<< (Edge);
 
 friend std::ostream & operator<< (std::ostream & output , const Edge ) ;

};


 #endif