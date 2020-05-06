 
#include <stdio.h>

int a=1;

int main() {
  int b=2;
  {
	int temp;
	temp = a;
	a = b;
	b = temp;
  }
}
