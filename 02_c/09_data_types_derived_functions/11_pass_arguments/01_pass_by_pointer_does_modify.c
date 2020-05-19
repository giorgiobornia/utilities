 
void swap(int *px, int *py) {
    
int temp;
temp = *px;
*px = *py; /* lavora sugli argomenti */
*py = temp; 

}

main() {

    int a, b;
swap(&a,&b); /* modifica a,b */

return 0;

}
