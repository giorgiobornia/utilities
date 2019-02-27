#include <iostream>
using namespace std;


template<class X> void genericSwap( X &a, X &b ) {
       X tmp;
 
       tmp = a;
       a = b;
       b = tmp;
     }
     
     int main(void) {
       int num1 = 5;
       int num2 = 21;
       cout << "Before, num1 is " << num1 << " and num2 is " << num2 << endl;
       genericSwap( num1, num2 );
       cout << "After, num1 is " << num1 << " and num2 is " << num2 << endl;
       char c1 = 'a';
       char c2 = 'z';
       cout << "Before, c1 is " << c1 << " and c2 is " << c2 << endl;
       genericSwap( c1, c2 );
       cout << "After, c1 is " << c1 << " and c2 is " << c2 << endl;
       return( 0 );
     }