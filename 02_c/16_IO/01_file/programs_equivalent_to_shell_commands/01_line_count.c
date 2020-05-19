 #include <stdio.h>
 
 //same as wc -l
 
main()
{
int c, nl;
nl = 0;
while((c = getchar()) != EOF)
if (c == '\n')
++nl;
printf("%d\n",nl);
}

// Si noti che in C un carattere tra apici è un valore intero che corrisponde al
// valore numerico del carattere nel set di caratteri della macchina (e.g., ’A’ è il
// valore 65 in ASCII).
