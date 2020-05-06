#include <stdio.h>

/* --------------------------------- *
 * 
 * --------------------------------- */
 /* primitive data types:
   * 
   * int
   * float
   * double
   * char
   * 
   */

  /* primitive data type modifiers:
   * 
   * short, long
   * unsigned, signed
   * 
   */

int main()  {
    


/* --------------------------------- */
  int my_int;
  
  short    int my_int_short;
  long     int my_int_long;
  unsigned int my_int_uns;
  signed   int my_int_sig;

  short unsigned int my_int_s_u;
  short signed   int my_int_s_s;
  long  unsigned int my_int_l_u;
  long  signed   int my_int_l_s;
  
  long  long  int my_int_long_long;
//   short short       int gsdg;
//   signed signed     int asdgasdg;
//   unsigned unsigned int asga;
  
  long  my_without;    /* shorthand for long int  */
  short my_without2;   /* shorthand for short int */
  
  /* I think int is like the default type, if there is only a modifier like short/long/signed/unsigned */

/* --------------------------------- */
  float my_fl;
  
//   short    float    my_fl_short; 
//   long     float     my_fl_long;
//   unsigned float my_fl_uns;
//   signed   float   my_fl_sig;
  
  
/* --------------------------------- */
  double my_doub;

//   short double my_doub_short;
  long double  my_doub_long;
//   unsigned double my_doub_uns; 
//   signed double my_doub_sig;
  
//   long  long  double rnh;

// others are not possible, because some single ones are not possible
  
/* --------------------------------- */
  char my_char;
  
//   short char my_char_short;
//   long char  my_char_long;
  unsigned char my_char_uns; 
  signed char  my_char_sig;

// others are not possible, because some single ones are not possible

// Signed is the default unless otherwise specified  
//  The only case where 'signed' is not redundant is with char
// According to the standard, char, signed char and unsigned char are three different types  
  
/* ----- sizeof -------------------- */

/* It is better to use %zu instead of %d for sizeof, because its output is of type size_t */

/* --------------------------------- */
  printf("======= int ========\n");
  printf("bytes per int:                %d \n", sizeof(int) );
  printf("bytes per short int:          %d \n", sizeof(short int) );
  printf("bytes per long int:           %d \n", sizeof(long int) );
  printf("bytes per unsigned int:       %d \n", sizeof(unsigned int) );
  printf("bytes per signed int:         %d \n", sizeof(signed int) );
  printf("bytes per short unsigned int: %d \n", sizeof(short unsigned int) );
  printf("bytes per short signed int:   %d \n", sizeof(short signed int) );
  printf("bytes per long unsigned int:  %d \n", sizeof(long unsigned int) );
  printf("bytes per long signed int:    %d \n", sizeof(long signed int) );
  
  printf("bytes per long long int:      %d \n", sizeof(long long int) );

   printf("bytes per int using the var.: %d \n", sizeof(my_int) );  /* it can work also with variables, not only with types */
 
/* --------------------------------- */
  printf("======= float ========\n");
  printf("bytes per float:              %d \n", sizeof(float) );
  
/* -------------------------------------- */
  printf("======= double ========\n");
  printf("bytes per double:             %d \n", sizeof(double) );
  printf("bytes per long double:        %d \n", sizeof(long double) );
  
/* -------------------------------------- */
  printf("======= char ========\n");
  printf("bytes per char:               %d \n", sizeof(char) );
  printf("bytes per unsigned char:      %d \n", sizeof(unsigned char) );
  printf("bytes per signed char:        %d \n", sizeof(signed char) );
  
  
  
/* ----- assignment -------------------- */
/* --------------------------------- */
  my_int       = 12;
  
  my_int_short = 13;
  my_int_long  = 14;
  my_int_uns   = -15;
  my_int_sig   = 16;
  
  my_int_s_u   = 17;
  my_int_s_s   = 18;
  my_int_l_u   = 19;
  my_int_l_s   = 20;

/* --------------------------------- */
  my_fl = 2.3;
  
/* --------------------------------- */
  my_doub =  2.3;
  my_doub_long = 2.4;

/* --------------------------------- */
  my_char = 'p';     /* single quotes, not double quotes! */
  my_char_uns = 'q';
  my_char_sig = 'r';
  

/* ----- format specifiers -------------------- */

  printf("Correct format specifiers\n");
/* --------------------------------- */
  printf("%d\n", my_int       );
  
  printf("%d\n", my_int_short );
  printf("%d\n", my_int_long  );
  printf("%u\n", my_int_uns   );  //%d would be a double mistake
  printf("%d\n", my_int_sig   );
  
  printf("%d\n", my_int_s_u   );
  printf("%d\n", my_int_s_s   );
  printf("%d\n", my_int_l_u   );
  printf("%d\n", my_int_l_s   );
  
/* --------------------------------- */
  printf("%f\n", my_fl);
  
/* --------------------------------- */
  printf("%f\n", my_doub); 
  printf("%f\n", my_doub_long);  //%llf
  
/* --------------------------------- */
  printf("%c\n", my_char   );
  printf("%c\n", my_char_uns );
  printf("%c\n", my_char_sig );

         
//   d = 's'; /* single quotes, not double quotes! */
//   f = b;
// 
//   /* print their values */
//   printf("Correct format specifiers\n");
//       
//   printf("int    a:       %d \n", a);
//   printf("unsigned int j: %u \n", j);
//   printf("float  b: %e \n", b);
//   printf("double c: %e \n", c);
//   printf("char   d: %c \n", d);
//   printf("float  f: %e \n", f);
//   
//   printf("Mismatched format specifiers: you will get complete errors!\n");
//   
//   printf("int    a:       %f \n", a);
//   printf("unsigned int j: %d \n", j);
//   printf("float  b: %d \n", b);
//   printf("double c: %d \n", c);
// //   printf("char   d: %s \n", d);  /*seg fault*/
//   printf("char   d: %d \n", d);
//   printf("float  f: %d \n", f);
// 
//   
// 
// 
//   /* -------- see their address ----------------- */
//   printf("address of a: %d \n", &a);
//   printf("address of a: %d \n", (long int) &a);
//   printf("address of b: %d \n", (long int) &b);
//   printf("address of c: %d \n", (long int) &c);
//   printf("address of d: %d \n", (long int) &d);
//   printf("address of f: %d \n", (long int) &f);


}


