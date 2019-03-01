#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define N 5

void Crash(size_t max){
char a[N];
int b[100];
size_t i;
for (i=0;i<max;i++)
	a[i]=48;
}

int main(int argc, char **argv)
{
//Crash(INT_MAX);
char * c;
int d;
c=malloc(sizeof(char)*10);
scanf("%d",&c[0]);
printf("%d",c[0]*2);
printf("%d",d);
return;
}

