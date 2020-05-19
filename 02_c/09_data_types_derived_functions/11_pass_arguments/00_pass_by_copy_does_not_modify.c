 void swap(int x, int y)
{
int temp;
temp = x;
x = y;
 /* works on a copy */
y = temp; 
}

main()
{
int a, b;

swap(a,b); /* non modifica a, b  */

return 0;
}
