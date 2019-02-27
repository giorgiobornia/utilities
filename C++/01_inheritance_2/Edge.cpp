#include <iostream>
#include "Element.hpp"
#include "Edge.hpp"

using namespace std;


  Edge::Edge(int myint,double mydouble,int mydear) : Element(myint,mydouble)
  
  {
    
    direction = mydear;
    
  }
void Edge :: show_id() const {
  cout<<"I am Edge" << std::endl ; }
  
  
 Edge Edge::operator<< (Edge var_in) { 
   
   cout<<"I am in the homogeneous operator " << var_in.get_N_Nodes() << std::endl;
   
   return var_in;
}

  std::ostream &  operator<< (std::ostream & output , const Edge ggg_in) {

   std::cout << "I am in the heterogeneous operator " << std::endl;
   
   return output;
}