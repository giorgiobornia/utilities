#include <stdio.h>

// type declaration: fruits is an enum type
enum fruits {
    
    apples,
    bananas,
    oranges
    
};

enum veggies {
    
    broccoli = 14,
    zucchine,
    eggplants
    
};


 enum  { /* anonymous enum */
    
    broccoli2 = 14,
    zucchine2,
    eggplants2
    
} var_no_type;  /* global variable */




typedef enum dishes {
    
    spaghetti,
    pizza,
    parmigiana
    
} dishes_alias;


enum tag {
      a, b, c, d = 20, e, f, g = 20, h
} var;


int main() {
    
   int fruits_int; 
   enum fruits fruits_var;      /* fruits_var is a variable of enum type */ 
   dishes_alias dishes_var;  /* no need for the word enum */
   
   
   printf("%d\n", fruits_var);  /* You print what is in that memory location - could be anything */

//    scanf("%d", &fruits_var);
//    printf("%d\n", fruits_var);
   
   fruits_var = oranges; /* An enum value is assigned to a variable of enum type */ 
                         /* the words listed in the enum are aliases for integral constants */
   printf("%d\n", fruits_var);
   fruits_int = apples; /* An enum value is assigned to a variable of int type */ 
   printf("%d\n", fruits_int);
   
   fruits_var = 74; /* An integral constant is assigned to a variable of enum type */
   printf("%d\n", fruits_var);
   
   fruits_var = 96.39;  /* A double constant is assigned to a variable of enum type - Truncation takes place */
   printf("%d\n", fruits_var);
   
   /* So, variables of enum type seems to behave exactly like an int variable */
   /* So, why declare a variable as enum type or as int type? */
   
   enum veggies veggies_var;   
   printf("%d\n", veggies_var); /* You print what is in that memory location - could be anything */
   

   printf("%d\n", var_no_type);

   
   
   
 return 0;
  
}
