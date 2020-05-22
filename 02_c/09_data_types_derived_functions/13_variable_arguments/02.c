#include <stdio.h>
#include <stdarg.h>

void stampa_argomenti(char *fmt, ...)
{
    
va_list ap;
int d;
char c, *p, *s;

va_start(ap, fmt);

while (*fmt)
switch(*fmt++) {
  case 's':
 /* string */
s = va_arg(ap, char *);
printf("string %s\n", s);
break;
  case 'd':
 /* int */
d = va_arg(ap, int);
printf("int %d\n", d);
break;
  case 'c':
 /* char */
c = va_arg(ap, int/*char*/); /* with char it gives a warning and then the run says "Illegal instruction" */
printf("char %c\n", c);
break;
}
va_end(ap);

}

int main () {

stampa_argomenti ( "sdc" , "stringa" , (int) 10 , (char)'h' );

stampa_argomenti ("s" , "stringa2");

return 0;

}
