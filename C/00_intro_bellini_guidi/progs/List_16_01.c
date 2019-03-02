#include <stdio.h>

void fun1(void), fun2(void), fun3(void);

struct voceMenu {
  char *msg;           /* prompt di voce di menu */
  void (*fun)(void);   /* funzione da innescare */
};

/* Inizializza il vettore di strutture menu
assegnando il messaggio della voce di menu
e la relativa funzione                     */

struct voceMenu menu[] = {
  "1. Funzione fun1\n", fun1,
  "2. Funzione fun2\n", fun2,
  "3. Funzione fun3\n", fun3,
  "0. Fine\n", NULL, NULL , NULL
};

void main()
{
int scelta;
struct voceMenu *p;
int loop = 0;

while(loop==0) {
  for(p=menu; p->msg!=NULL; p++) /* presentazione del menu */
    printf("%s", p->msg);

  printf("\n\nScegliere l'opzione desiderata: ");
  scanf("%d", &scelta);

  if(scelta==0)      /*uscita programma */
    loop = 1;
  else
    /* esecuzione della funzione associata alla scelta */
    (*menu[scelta-1].fun)();
}
}

void fun1(void)
{printf("\n\n Sto eseguendo fun1\n\n\n");}

void fun2(void)
{printf("\n\n Sto eseguendo fun2\n\n\n");}

void fun3(void)
{printf("\n\n Sto eseguendo fun3\n\n\n");}
