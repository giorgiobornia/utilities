 #include <stdio.h>

 /*
  * const does not mean that the value is known at compile time!
 It means that, ONCE INITIALIZED, the variable cannot be modified!
 */
 
int main() {
    
    
  int g;
  
  scanf("%d", &g);
  
  const int h = g;
  
    printf("%d\n", h);
   
    
 return 0;
 
}  
