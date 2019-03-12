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
int print_to_terminal(char * a)  {

 char transl[62] = "!ek;dc i@bK'(q)-[w]*%n+r3#l,{}:\nuwloca-O;m .vpbks,fxntdCeghiry"; 
 //31+31 chars, \n is half-way through, from the second part we pick the char to be printed //here is the translation between our encryption alphabet and the human alphabet
 
// printf("The current position in the big string is %d", &a[0]);
 
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
//     else { printf("Stop"); } of course many times you would get here
 
 return 1;
 
} 
 
 
void parse_encrypted_code(int t, int b, char * a)  {
//basically here the string pointer "a" changes every time as a position in the "encrypt" string     

//                   On the /first/second/third/fourth/fifth/sixth/seventh/eighth/ninth/tenth/eleventh/twelfth/ day of Christmas my true love gave to meN/twelve drummers drumming, /eleven pipers piping, /ten lords a-leaping,N/nine ladies dancing, /eight maids a-milking, /seven swans a-swimming,N/six geese a-laying, /five gold rings,N/four calling birds, /three french hens, /two turtle dovesNand /a partridge in a pear treeTNN/
char encrypt[408] = "@n'+,#'/*{}w+/w#cdnr/+,{}r/*de}+,/*{*+,/w{%+,/w#q#n+,/#{l,+,/n{n+,/+#n+,/#;#q#n+,/+k#;*+,/'r :'d*'3,}{w+K w'K:'+}e#';dq#'l q#'+d'K#!/+k#;q#'r}eKK#}w'r}eKK{nl]'/#;#q#n'){)#}w'){){nl]'/+#n';d}rw' i;# ){nl]!/n{n#'; r{#w'r nc{nl]'/#{l,+'K {rw' iK{;[{nl]'/w#q#n'wk nw' iwk{KK{nl]!/w{%'l##w#' i; :{nl]'/*{q#'ld;r'}{nlw]!/*de}'c ;;{nl'-{}rw]'/+,}##'*}#nc,',#nw]'/+kd'+e}+;#'rdq#w! nr'/ ') }+}{rl#'{n' ')# }'+}##(!!/";



if (1 < t) {  //t min = 2, t max = 13
    
// printf("t = %d",t);

//this t == 2 is reached only at the beginning of each paragraph    
if ( t == 2 )    {
    print_to_terminal(encrypt); //this prints "On the " only   
    parse_encrypted_code(-73, 1 - b, NULL );   //First-second
    parse_encrypted_code(-73,   -13, NULL );   //day of Christmas
} 



//from the 2nd row
if (t < b )     {  
     parse_encrypted_code(t+1, b, NULL); 
}


int b_in = -27 + t;
// printf("b = %d",b_in);
   parse_encrypted_code(-73, b_in, NULL );

     
//increase b for next paragraph     
 if (t == 2 && b < 13)  {
     parse_encrypted_code(2, b+1, NULL );   
}

}




else if (t < -72) {
    
     if (b > 0) abort();
     parse_encrypted_code(b, 308, encrypt);  //this ultimately sends to "t == -1"
     
}



else if ( -50 <= t &&  t < -1)               { // Based on the "t" value, this ends on t == -1
    
    int slashes_to_skip = -t;

//     printf("C%d",slashes_to_skip);
    
    a = skip_one_slash(a);

    t = t+1; 
    parse_encrypted_code(t, 307 , a ); 
    
}

else if (             t == -1)               {
    
        a = skip_one_slash(a);
        print_to_terminal(a);  //this prints everything except "On the "
    
}




}




 int main() {
  
//     char ch[2]; ch[0] = "%"; ch[1] = "s";
    char * ch = "%s"; //his is a way to initialize the string
    int seed_t = 2;
    int seed_b = 2;
    parse_encrypted_code(seed_t,seed_b,ch);

    return 0;
 }



/*Are both parts of a logical || evaluated or if the first is true the second is not even evaluated? No, it is short-circuited, going from left to right! */
