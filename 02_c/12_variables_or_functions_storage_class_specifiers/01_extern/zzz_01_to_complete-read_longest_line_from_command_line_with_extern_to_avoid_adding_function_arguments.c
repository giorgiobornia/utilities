 
#include <stdio.h>
#define MAXLINE 1000
 /* lunghezza massima di una linea */
int max; /* massima lunghezza trovata finore */
char line[MAXLINE]; /* linea di input corrente */
char longest[MAXLINE]; /* linea piu‘ lunga corrente */
int getline(void);
void copy(void);
main()
{
int len;
extern int max;
extern char longest[MAXLINE];
max=0;

while ((len=getline()) > 0)
if (len > max)
{ max=len;
copy();
}
if (max > 0) /* c’era almeno una linea in input */
printf("%s", longest);
return 0;
}


// Esercizio: definire le funzioni
// int getline(void)
// void copy(void)

// NOTICE THAT THIS TIME THESE FUNCTIONS DO NOT HAVE ANY ARGUMENTS!!!
