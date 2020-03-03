/* Use 'man operator', although is a little too synthetic and can be misleading */

/* How can I know if each couple of instructions does exactly the same thing? By diffing the assembler? */

int main() {
    
    int a, b, c;
    
     a = b + c;
     a = (b + c);
     
     a + b - c;
     (a + b) - c;
     
      a + b * c;
      a + (b * c);
      
      a + b * a < b;
      ( a + (b * a) ) < b;
      
      a + b && a < b;
      (a + b) && (a < b);
      
      a * c != b  || a > b;
      ( (a * c) != b ) || (a > b);
    
}
