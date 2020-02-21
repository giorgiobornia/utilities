#include <iostream>


class Class {

//   private:   //means that the access from other contexts (frames) is forbidden 
//     double casa;
public:

   double casa;

// Class() {
//   
//     std::cout << "No argument constructor" <<  std::endl;
// 
// }
  
  
Class(double gggi, int pippo=9) {
  casa=3;
  std::cout << "Ciao" << pippo << std::endl;
}

 ~Class() {}
 
 };






int main(int argc, char** argv) {

//   Class* gigio = new Class();

 Class gigio(1.);

std::cout << "Sono nel main" << gigio.casa << std::endl;

return 0;

}

//  Class gigio;  //like this, it calls the constructor it finds.
                     //If there is more than one constructor, then it has an ambiguity.
// Class()  ok
// Class(), Class(int pippo=7) ambiguity.
// Class(), Class(int pippo)   ambiguity.


//  Class gigio();  //like this, it should call the no argument constructor.
                       //instead, it does not accept these situations:
		       // Class() no
                       //Class(int pippo=7) no
                       // Class(), Class(int pippo=7) no
                       // Class(), Class(int pippo)   no 
//to get the default value in the argument of the constructor,
// you still have to call it without parentheses Class gigio;

//if you have more than one argument, things change. This works:
// Class(double gggi, int pippo=9) {
//int main {  Class gigio(1.);}
