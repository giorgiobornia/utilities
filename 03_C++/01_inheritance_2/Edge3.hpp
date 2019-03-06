#ifndef _Edge3_hpp_
#define _Edge3_hpp_

#include "Element.hpp"
#include "Edge.hpp"

#include <iostream>
#include <sstream>
#include "Element.hpp"
#include "Edge.hpp"
using namespace std;


template <class T>
class Edge3: public Edge{
  
  T aaa;

public:
  Edge3(int myint,double mydouble,int mydear,const T & aaa_in);
  
 virtual void show_id() const;
 
//   std::basic_ostream<char> operator<< (T);

};



//  std::ostream<char> operator << (Edge3);



template <class T>
  Edge3<T>::Edge3(int myint,double mydouble,int mydear,const T & aaa_in) 
  : aaa(aaa_in),
  Edge(myint,mydouble,mydear)
  {  /*aaa = aaa_in;*/ }

template <class T>
void Edge3<T>::show_id() const {
  std::string mystring = "I am Edge3 and aaa is ";
   cout <<  mystring << aaa << std::endl; 
}
  

 #endif