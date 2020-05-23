 #include <stdio.h>

//  ./countchar < file

//  same as wc -c file

 
int main()
{
long nc;
nc = 0;

while(getchar() != EOF)
{
++nc;
}


printf("%ld\n",nc);
}
