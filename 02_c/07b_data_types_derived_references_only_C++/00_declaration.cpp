#include <iostream>


int main() {
    
//     int & var1;  /* does not compile: declared as reference but not initialized */
//     int & var2 = 18;  /* does not compile: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int */
//     const int & var3;  /* does not compile: declared as reference but not initialized */
//     const int & const var4 = 18;  /* does not compile: ‘const’ qualifiers cannot be applied to ‘const int&’ */
     const int & var4 = 18;   
    
    printf("%d\n", var4);
    
    std::cout << var4 << std::endl;
    
 return 0;
 
}
