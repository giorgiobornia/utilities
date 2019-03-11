#include <stdio.h>

 /* Operator Precedence: if you open a round parenthesis somewhere the compiler tells you where he expects that to be closed. That is a method to figure out the precedences in a given code */

int main(int t, int b, char * a)

// int t;
// int b;
// char * a;  //either you declare in the interface, or you declare at the beginning, BEFORE the curly bracket that opens the body of the function.

{
    

int return_int;


if (1 < t) { /* t = 2, 3, ... */
    
 int a_1;   

if ( t < 3 )     { int b_1 =     main(-86, 0, a+1 ) + a;
                   int b_2 = a + main(-87, 1 - b, b_1);
                       a_1 =     main(-79, -13, b_2 );  } 
else if (t >= 3) { a_1 = 1; }


int a_2;  

 if (t < b )        { a_2 = main(t+1, b, a); }
 else  if (t >= b)  { a_2 = 3; }


 int a_3;

if ( main(-94, -27 + t, a ) && t == 2 ) { a_3 = ( b < 13 ?  main(2, b+1, "%s %d %d\n" ) : 9 ); }  /*watch out because here commutativity of && is not valid!*/
else                                    { a_3 = 16; }

 
return_int = ( a_1, a_2, a_3 );  /*What is this operation?*/

}


else if (t < -72) {

return_int = main(b, t, "@n'+,#'/*{}w+/w#cdnr/+,{}r/*de}+,/*{*+,/w{%+,/w#q#n+,/#{l,+,/n{n+,/+#n+,/#;#q#n+,/+k#;*+,/'r :'d*'3,}{w+K w'K:'+}e#';dq#'l q#'+d'K#!/+k#;q#'r}eKK#}w'r}eKK{nl]'/#;#q#n'){)#}w'){){nl]'/+#n';d}rw' i;# ){nl]!/n{n#'; r{#w'r nc{nl]'/#{l,+'K {rw' iK{;[{nl]'/w#q#n'wk nw' iwk{KK{nl]!/w{%'l##w#' i; :{nl]'/*{q#'ld;r'}{nlwb!/*de}'c ;;{nl'-{}rw]'/+,}##'*}#nc,',#nw]'/+kd'+e}+;#'rdq#w! nr'/ ') }+}{rl#'{n' ')# }'+}##(!!/");
    
}
 

else if ( -72 <= t && t < -50) { while (b != a[0]) a = a + 1; 
                                 char char_out = a[31];  
                                 return_int = putchar(char_out); }
/* This putchar is the command that prints to terminal!!! Without this, the program has no output. The calls are such that the char on pos. 31 is always the right one to print to terminal! */

// else if ( -72 <= t && t < -50 && b != a[0]) {  return_int = main(-65, b , a + 1);  }  /*If b != a[0], increase the pointer of a until b == a[0], so that you get to print above */

else if ( -50 <= t &&  t < 0)               {  while (a[0] != '/') a = a + 1;  return_int = main(t + 1, b , a + 1); }

else if ( t == 1 )                          {  return_int = main(2, 2, "%s"); }

else /* t == 0 */                           {  return_int = ( (a[0] == '/') || main(0, main(-61, a[0], "!ek;dc i@bK'(q)-[w]*%n+r3#l,{}:\nuwloca-O;m .vpbks,fxntdCeghiry"), a + 1) ); } /*Are both parts of the || evaluated or if the first is true the second is not even evaluated? No, it is short-circuited, going from left to right! */


return return_int;


}
