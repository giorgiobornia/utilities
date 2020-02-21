/* Trasformazione della rappresentazione di un grafo
   da una matrice di adiacenze a una lista di successori */

#include <stdio.h>
#include <malloc.h>

struct nodo {              /* struttura di un nodo */
  char inf;
  struct successore *pun;
};

struct successore {       /* elemento della lista di successori */
  int inf;
  struct successore *pun;
};

int a[10][10];            /* matrice di adiacenze */
struct nodo s[10];        /* array di nodi */
int n;                    /* numero di nodi */

void matAdiacenze(void);
void visMatAdiacenze(void);
void successori(void);
void creaSucc(int, int);
void visita(void);

int main()
{
matAdiacenze();       /* creazione della matrice di adiacenze */
visMatAdiacenze();    /* visualizzazione della matrice */
successori();         /* creazione delle liste di successori */
visita();             /* visual. dei successori di ogni nodo */
}


/* Crea la matrice di adiacenze */

void matAdiacenze(void)
{
int i, j;
char invio;

printf("\nNumero di nodi: ");
scanf("%d", &n);
scanf("%c", &invio);

for(i=0; i<n; i++) {            /* richiesta etichette dei nodi */
  printf("\nEtichetta del nodo: ");
  scanf("%c", &s[i].inf);
  scanf("%c", &invio);
  s[i].pun = NULL;
}

for(i=0; i<n; i++)              /* richiesta archi orientati */
  for(j=0; j<n; j++) {
    printf("\nArco orientato da [%c] a [%c] (0 no, 1 si) ? ",
            s[i].inf, s[j].inf);
    scanf("%d", &a[i][j]);
  }
}


/* Visualizza la matrice di adiacenze */

void visMatAdiacenze(void)
{
int i, j;

printf("\nMATRICE DI ADIACENZE\n");
for(i=0; i<n; i++)               /* visualizza i nodi (colonne) */
  printf("   %c", s[i].inf);

for(i=0; i<n; i++) {
  printf("\n%c  ", s[i].inf);    /* visualizza i nodi (righe) */
  for(j=0; j<n; j++)
    printf("%d   ", a[i][j]);    /* visualizza gli archi */
}
}


/* Crea le liste di successori. Per ogni arco rappresentato 
   nella matrice di adiacenze chiama creaSucc              */

void successori(void)
{
int i, j;

for(i=0; i<n; i++)
  for(j=0; j<n; j++) {
    if(a[i][j]==1)
      creaSucc(i, j);
   }
}


/* Dato un certo arco nella matrice di adiacenze, crea 
il rispettivo elemento di lista                        */

void creaSucc( int i, int j )
{
struct successore *p;

if(s[i].pun==NULL) {     /* non esiste la lista dei successori */
  s[i].pun = (struct successore *)(malloc(sizeof(struct successore)));
  s[i].pun->inf = j;
  s[i].pun->pun = NULL;
}
else {                   /* esiste la lista dei successori */
  p = s[i].pun;
  while(p->pun!=NULL)
    p = p->pun;
  p->pun = (struct successore *)(malloc(sizeof(struct successore)));
  p = p->pun;
  p->inf = j;
  p->pun = NULL;
}
}


/* Per ogni nodo del grafo restituisce i suoi successori.
   Lavora sulle liste di successori                      */

void visita(void)
{
int i;
struct successore *p;

printf("\n");

for(i=0; i<n; i++) {
  printf("\n[%c] ha come successori: ", s[i].inf);
  p = s[i].pun;
  while(p!=NULL) {
    printf(" %c", s[p->inf].inf);
    p = p->pun;
  }
}
}
