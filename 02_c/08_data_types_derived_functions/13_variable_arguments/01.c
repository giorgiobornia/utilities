#include <stdio.h>
#include <stdarg.h>

void print_lista_argomenti(int narg, ...)
{
va_list va;
int i;
char *ptrchar;
/* va_start inizializza va_list all'argomento, tra passati a
print_lista_argomenti, che segue l'argomento narg indicato come
secondo argomento nella va_start, cioè inizializza la lista va_list al
primo degli argomenti variabili */
va_start(va,narg);
for(i=0;i<narg;i++)
{
ptrchar=va_arg(va,char*); /*ptrchar punta alla stringa passata*/
printf("%d %s\n",i,ptrchar);
}
va_end(va);
}


int main() {
    
    print_lista_argomenti(0);
print_lista_argomenti(5,"primo","secondo","terzo","quarto","quinto");

    
 return 0; 
 
}
