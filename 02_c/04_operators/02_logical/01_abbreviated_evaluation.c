 #include <stdio.h>

 
 int operand() {
     
    printf("I am an operand\n");   
  
 }

 
int main() {
    
  printf("&&, first false\n");   
    0 && operand();  //second is not evaluated because first is false already
    
  printf("||, first false\n");   
    0 || operand();  //second is evaluated because first is false so it's not enough to evaluate the first operand to figure out what the global truth value is
    
  printf("&&, first true\n");   
    1 && operand();  //second is evaluated because first is true  so it's not enough to evaluate the first operand to figure out what the global truth value is
    
  printf("||, first true\n");   
    1 || operand();  //second is not evaluated because first is true already
    
  return 0;
}
