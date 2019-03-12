#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

 /* Operator Precedence: if you open a round parenthesis somewhere the compiler tells you where he expects that to be closed. That is a method to figure out the precedences in a given code */

char * skip_one_slash(char * a)  {
 
while (a[0] != '/') a = a + 1;  
a = a + 1;
assert( a[0] != '/');

return a;

}


 //this prints between two slashes
void print_between_adjacent_separators(char * a)  {

 char transl[62] = "!ek;dc i@bK'(q)-[w]*%n+r3#l,{}:\nuwloca-O;m .vpbks,fxntdCeghiry"; 
 //31+31 chars, \n is half-way through, from the second part we pick the char to be printed //here is the translation between our encryption alphabet and the human alphabet
 
 char separator = '/';
 
    int char_encrypted = a[0];

    
    while (char_encrypted != separator) {
        
    char * pos_start = &transl[0];
    while (pos_start[0] != char_encrypted)   pos_start = pos_start + 1;  

    char char_translated = pos_start[31];  
    
    putchar(char_translated); 
    
    a = a + 1;
    char_encrypted = a[0];
                                                        
    }
 
 
} 
 

void find_position_and_print(int b, char * encrypt)  {
 
     if (b > 0) abort();

     
     char * a = &encrypt[0];
     

     while (b <= - 1) {
//     printf("B%d",b);
         
    a = skip_one_slash(a);
    b = b+1;
         
     }

     print_between_adjacent_separators(a);
      
} 
 
 
 

 int main() {
  
//basically here the string pointer "a" changes every time as a position in the "encrypt" string     

//                   On the /first/second/third/fourth/fifth/sixth/seventh/eighth/ninth/tenth/eleventh/twelfth/ day of Christmas my true love gave to meN/twelve drummers drumming, /eleven pipers piping, /ten lords a-leaping,N/nine ladies dancing, /eight maids a-milking, /seven swans a-swimming,N/six geese a-laying, /five gold rings,N/four calling birds, /three french hens, /two turtle dovesNand /a partridge in a pear treeTNN/
char encrypt[408] = "@n'+,#'/*{}w+/w#cdnr/+,{}r/*de}+,/*{*+,/w{%+,/w#q#n+,/#{l,+,/n{n+,/+#n+,/#;#q#n+,/+k#;*+,/'r :'d*'3,}{w+K w'K:'+}e#';dq#'l q#'+d'K#!/+k#;q#'r}eKK#}w'r}eKK{nl]'/#;#q#n'){)#}w'){){nl]'/+#n';d}rw' i;# ){nl]!/n{n#'; r{#w'r nc{nl]'/#{l,+'K {rw' iK{;[{nl]'/w#q#n'wk nw' iwk{KK{nl]!/w{%'l##w#' i; :{nl]'/*{q#'ld;r'}{nlw]!/*de}'c ;;{nl'-{}rw]'/+,}##'*}#nc,',#nw]'/+kd'+e}+;#'rdq#w! nr'/ ') }+}{rl#'{n' ')# }'+}##(!!/";


    
for (unsigned b = 2; b < 14; b ++)  {


    find_position_and_print(0, encrypt); //this prints "On the " only   
    find_position_and_print(1 - b,encrypt);   //First-second
    find_position_and_print(-13,  encrypt);   //day of Christmas




for (unsigned t_in = b; t_in >= 2; t_in --)  {
    int b_in = -27 + t_in;
    find_position_and_print(b_in,encrypt);
   }

 }

    return 0;
}



/*Are both parts of a logical || evaluated or if the first is true the second is not even evaluated? No, it is short-circuited, going from left to right! */
