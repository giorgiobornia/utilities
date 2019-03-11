#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

 /* Operator Precedence: if you open a round parenthesis somewhere the compiler tells you where he expects that to be closed. That is a method to figure out the precedences in a given code */

 

 
int print_to_terminal(char * a)  {

 char transl[62] = "!ek;dc i@bK'(q)-[w]*%n+r3#l,{}:\nuwloca-O;m .vpbks,fxntdCeghiry"; 
 
    int char_that_I_want_encrypted = a[0];
    if (char_that_I_want_encrypted != '/') {
        
//     char_that_I_want_encrypted = a[0];
    
    char * a_tmp = &transl[0];
    while (a_tmp[0] != char_that_I_want_encrypted) { a_tmp = a_tmp + 1; }  //he compares the ASCII number with the number that you want. He decides where is the beginning and takes the 31 component
    char char_out = a_tmp[31];  
    putchar(char_out); /* This putchar is the command that prints to terminal!!! Without this, the program has no output. The calls are such that the char on pos. 31 is always the right one to print to terminal! */
    
    a = a + 1;
     print_to_terminal(a);  //would like to remove this recursion
                                                        
    } 
 
 return 1;
 
} 
 
 
int main2(int t, int b, char * a)  {
    

 //31+31 chars, \n is half-way through, from the second part we pick the char to be printed //here is the translation between our encryption alphabet and the human alphabet


int return_int;

//the initial value of t is 1
//the initial value of b is random

if (1 < t) {
    

//this t == 2 is reached only at the beginning of each paragraph    
if ( t == 2 )    { int b_1 =     main2(-86,     0, a+1 ) + a;
                   int b_2 = a + main2(-87, 1 - b, b_1 );
                                 main2(-79,   -13, b_2 );  } 


//this is reached only at the beginning of the 2nd line of each paragraph, and it loops over the subsequent rows 
 if (t < b )     {  main2(t+1, b, a); } //increase t until t == b

 int b_in = -27 + t;
 int mainmin94 = main2(-94, b_in, a ); 
 
     if (t == 2 && mainmin94 && b < 13)  { return_int = main2(2, b+1, "%s %d %d\n" ); } //it stays here and increases b until b == 13
else if (t == 2 && mainmin94 && b >= 13) { return_int = 9;  }
else                                     { return_int = 16; }

}


else if (t < -72) {
    
    
    
// Here it generates the char to start from in the below -61 main call
//                   On the /first/second/third/fourth/fifth/sixth/seventh/eighth/ninth/tenth/eleventh/twelfth/ day of Christmas my true love gave to meN/twelve drummers drumming, /eleven pipers piping, /ten lords a-leaping,N/nine ladies dancing, /eight maids a-milking, /seven swans a-swimming,N/six geese a-laying, /five gold rings,N/four calling birds, /three french hens, /two turtle dovesNand /a partridge in a pear treeTNN/
char encrypt[408] = "@n'+,#'/*{}w+/w#cdnr/+,{}r/*de}+,/*{*+,/w{%+,/w#q#n+,/#{l,+,/n{n+,/+#n+,/#;#q#n+,/+k#;*+,/'r :'d*'3,}{w+K w'K:'+}e#';dq#'l q#'+d'K#!/+k#;q#'r}eKK#}w'r}eKK{nl]'/#;#q#n'){)#}w'){){nl]'/+#n';d}rw' i;# ){nl]!/n{n#'; r{#w'r nc{nl]'/#{l,+'K {rw' iK{;[{nl]'/w#q#n'wk nw' iwk{KK{nl]!/w{%'l##w#' i; :{nl]'/*{q#'ld;r'}{nlw]!/*de}'c ;;{nl'-{}rw]'/+,}##'*}#nc,',#nw]'/+kd'+e}+;#'rdq#w! nr'/ ') }+}{rl#'{n' ')# }'+}##(!!/";

//      printf("-72"); 
      if (b != 0)  return_int = main2(b, t, encrypt);  
 else if (b == 0)  return_int = print_to_terminal(encrypt); // when b = 0 it begins a paragraph    

}



else if ( -50 <= t &&  t < -1)               {  while (a[0] != '/') a = a + 1;  return_int = main2(t + 1, 307 , a + 1); }

else if (             t == -1)               {  while (a[0] != '/') a = a + 1;  a = a + 1; assert( a[0] != '/');    return_int = print_to_terminal(a);  }

else if ( t == 1 )                          {  return_int = main2(2, 2, "%s"); }



return return_int;


}




 int main() {
  
    char * ch;
    return main2(1,5,NULL);
     
 }



/*Are both parts of a logical || evaluated or if the first is true the second is not even evaluated? No, it is short-circuited, going from left to right! */
