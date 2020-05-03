#include <stdio.h>
#include <math.h>

//const pointer VS const value **************************
// Both the pointer of a variable and the value of that variable can be made "const", 
// in the sense that you can require that they cannot be modified once initialized

// In fact, you may want not only the value of a variable to be unchanged,
// but also the address that leads to that variable to be unchanged

// Analogy: A variable is like a house 
//          The POINTER of a variable is like the address of a house: 1108 Memorial Circle
//          The VALUE of the variable is like the content of the house: 2 beds, 1 table, ...

// The C syntax for const follows this rule:
//    the type qualifier "const" is attributed to the type that is to the LEFT of the word "const"
// However, when there is nothing to the left, "const" is attached to the first type at its right

// In view of this, let us translate into human language the declarations below:

// 1)
// double const var:    "var is a constant double" (like reading from right to left)
// const double var:    "var is a constant double" (same as before, more common to write like this)
// 
// With these, the value cannot be changed, and there is no pointer in the declaration

// 2)
// double const * var:  "var is a pointer to a constant double"
// const double * var:  "var is a pointer to a constant double" (same as before, more common to write like this)
// 
// With these, the pointer can be changed, the value cannot be changed 

// 3)
// double * const var:  "var is a constant pointer to a double"
// 
// With these, the pointer cannot be changed, the value can be changed 

// 4)
// double const * const var:  "var is a constant pointer to a constant double"
// const double * const var:  "var is a constant pointer to a constant double"  (same as before, more common to write like this)
// 
// With these, the pointer cannot be changed, the value cannot be changed 
//*******************************************************




  double compute_convergence_order(FILE * outfile, double const * const  x_n, const unsigned int counter_end)  {

      unsigned int i;
      
      double conv_order;
      
   for (i = 0; i < counter_end - 2; i++) {
       
       conv_order = log( fabs( ( x_n[i+3]  - x_n[i+2] ) / ( x_n[i+2]  - x_n[i+1] ) )  ) / log( fabs(  ( x_n[i+2]  - x_n[i+1] ) / ( x_n[i+1]  - x_n[i] ) )  );
       
   fprintf(outfile, "Convergence order: Iteration %d, p = %16.10e\n", i, conv_order);
       
   }
   
   return conv_order;

  }
