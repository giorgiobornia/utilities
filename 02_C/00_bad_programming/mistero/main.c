#include <stdio.h>
#include <stdlib.h>

 /* Operator Precedence: if you open a round parenthesis somewhere the compiler tells you where he expects that to be closed. That is a method to figure out the precedences in a given code */

int main(int t, int b, char * a)  {
    

 char transl[62] = "!ek;dc i@bK'(q)-[w]*%n+r3#l,{}:\nuwloca-O;m .vpbks,fxntdCeghiry"; 
 //31+31 chars, \n is half-way through, from the second part we pick the char to be printed //here is the translation between our encryption alphabet and the human alphabet


int return_int;

//the initial value of t is 1
//the initial value of b is random

if (1 < t) { /* t = 2, 3, ... */
    

//this t == 2 is reached only at the beginning of each paragraph    
if ( t == 2 )    { int b_1 =     main(-86,     0, a+1 ) + a;
                   int b_2 = a + main(-87, 1 - b, b_1 );
                                 main(-79,   -13, b_2 );  } 


//this is reached only at the beginning of the 2nd line of each paragraph, and it loops over the subsequent rows 
 if (t < b )     {  main(t+1, b, a); } //increase t until t == b

 int b_in = -27 + t;
 int mainmin94 = main(-94, b_in, a ); 
 
     if (t == 2 && mainmin94 && b < 13)  { return_int = main(2, b+1, "%s %d %d\n" ); } //it stays here and increases b until b == 13
else if (t == 2 && mainmin94 && b >= 13) { return_int = 9;  }
else                                     { return_int = 16; }

}


else if (t < -72) {
// Here it generates the char to start from in the below -61 main call
//                       On the /first/second/third/fourth/fifth/sixth/seventh/eighth/ninth/tenth/eleventh/twelfth/ day of Christmas my true love gave to meN/twelve drummers drumming, /eleven pipers piping, /ten lords a-leaping,N/nine ladies dancing, /eight maids a-milking, /seven swans a-swimming,N/six geese a-laying, /five gold rings,N/four calling birds, /three french hens, /two turtle dovesNand /a partridge in a pear treeTNN/
return_int = main(b, t, "@n'+,#'/*{}w+/w#cdnr/+,{}r/*de}+,/*{*+,/w{%+,/w#q#n+,/#{l,+,/n{n+,/+#n+,/#;#q#n+,/+k#;*+,/'r :'d*'3,}{w+K w'K:'+}e#';dq#'l q#'+d'K#!/+k#;q#'r}eKK#}w'r}eKK{nl]'/#;#q#n'){)#}w'){){nl]'/+#n';d}rw' i;# ){nl]!/n{n#'; r{#w'r nc{nl]'/#{l,+'K {rw' iK{;[{nl]'/w#q#n'wk nw' iwk{KK{nl]!/w{%'l##w#' i; :{nl]'/*{q#'ld;r'}{nlw]!/*de}'c ;;{nl'-{}rw]'/+,}##'*}#nc,',#nw]'/+kd'+e}+;#'rdq#w! nr'/ ') }+}{rl#'{n' ')# }'+}##(!!/");  //I think ( terminates, maybe  

//The sign of b decides where to go next    
}



else if ( -50 <= t &&  t < 0)               {  while (a[0] != '/') a = a + 1;  return_int = main(t + 1, b , a + 1); }  //this goes where a starts with /

else if ( t == 1 )                          {  return_int = main(2, 2, "%s"); }

else if ( t == 0 )                          { int char_that_I_want_encrypted = a[0];
                                                 if (char_that_I_want_encrypted == '/') { return_int = 1; }
                                               else {
                                                   char * a_tmp = &transl[0];
                                                   
                                                    while (a_tmp[0] != char_that_I_want_encrypted) { a_tmp = a_tmp + 1; }  //he compares the ASCII number with the number that you want. He decides where is the beginning and takes the 31 component
                                                    char char_out = a_tmp[31];  
                                                    putchar(char_out); /* This putchar is the command that prints to terminal!!! Without this, the program has no output. The calls are such that the char on pos. 31 is always the right one to print to terminal! */
                                 
                                                    int next = main(0, 307, a + 1);  //increases the char until it finds a /
                                                    
                                                   return_int = (0 || next ); 
                                                } /*Are both parts of the || evaluated or if the first is true the second is not even evaluated? No, it is short-circuited, going from left to right! */
                                            }

return return_int;


}
