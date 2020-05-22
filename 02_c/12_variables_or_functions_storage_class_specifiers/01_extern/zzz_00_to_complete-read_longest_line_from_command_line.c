 
#include <stdio.h>
#define MAXLINE 1000
 /* lunghezza massima di una linea */
int getline(char line[], int maxline);
void copy(char to[], char from[]);
main()
{
int len; /* lunghezza della linea corrente */
int max; /* massima lunghezza trovata finora */
char line[MAXLINE]; /* linea di input corrente */
char longest[MAXLINE]; /* linea piu’ lunga corrente */
max=0;
while ((len=getline(line, MAXLINE)) > 0)
if (len > max)
{ max=len;
copy(longest, line);
}
if (max > 0) /* c’era almeno una linea in input */
printf("%s", longest);
return 0;
}

//Esercizio

/* getline: legge e carica in s una linea, ritorna la lunghezza */
int getline(char s[], int lim)
/* copy: copia from in to; assume che to sia sufficientemente ampio */
void copy(char to[], char from[])
