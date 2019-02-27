
#include <iostream>
using namespace std;
#include "Element.hpp"
#include "newstruct.hpp"
#include "Edge.hpp"
#include "Edge3.hpp"
#include "Face.hpp"

void print_elem_id (Element & myelem);
// void print_elem_id (Edge & myedge);


int main ()
{
   
 Edge myedge(7,3.14,4);
 
 Edge3<double> myedge3(3,4.34,3,3.14);
 Edge3<int> myedge4(3,4.34,3,3);
 Edge3<std::string> myedge5(3,4.34,3,"I am Pushpi");

 Edge3<Edge> myedge6(3,4.34,3,myedge);

  
  Element myelement(myedge);
  
//   Element<Edge> myelement(myedge);
  
 Face myface = myface ;
//  Edge myedge1 = myedge;

  std::cout << myedge3 << myedge;
 
  print_elem_id(myelement);
  print_elem_id(myface);
  print_elem_id(myedge);
  print_elem_id(myedge3);
    print_elem_id(myedge4);
    print_elem_id(myedge5);
    print_elem_id(myedge6);

   
    
    
     return 0;
}


void print_elem_id (Element & myelem)
{
    myelem.show_id();
  return;
}

// void print_elem_id (Edge & myedge)
// {
//     myedge.show_id();
//   return;
// }




