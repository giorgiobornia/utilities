#include <iostream>


 void function_without_reference_argument_does_not_modify_passed_variable(double  a) {
     
  a = 17.03;
  
 }

 
 void function_with_reference_argument_modifies_passed_variable(double & a) { /* Notice that the writing with reference is simpler than with pointer */
     
  a = 9.6;
  
 }

 
 void function_with_pointer_argument_modifies_passed_variable(double * a) {
     
   * a = 3.14;
     
 }
 
 
 
int main() {

  
  double a = 8.1;
 
  std::cout << "Variable before: " << a << std::endl;
  
  function_with_reference_argument_modifies_passed_variable(a);
  
  std::cout << "Variable after: " << a << std::endl;
  
  function_without_reference_argument_does_not_modify_passed_variable(a);
   
  std::cout << "Variable after: " << a << std::endl;
  
  function_with_pointer_argument_modifies_passed_variable(&a);
  
  std::cout << "Variable after: " << a << std::endl;
  
  return 0;

}   
