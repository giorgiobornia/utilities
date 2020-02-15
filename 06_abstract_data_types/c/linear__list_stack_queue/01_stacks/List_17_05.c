/* GESTIONE DI UNA PILA
   Operazioni di inserimento, eliminazione e visualizzazione. 
   Utilizza una lista lineare per implementare la pila */

#include <stdio.h>
#include <malloc.h>

struct elemento {
  int inf;
  struct elemento *pun;
};

void gestionePila(void);
struct elemento *inserimento(struct elemento *, int ele);
struct elemento *eliminazione(struct elemento *, int *);
int pilaVuota(struct elemento *);
void visualizzazionePila(struct elemento *);

int main()
{
    
  gestionePila();
  
}


void gestionePila(void)
{
struct elemento *puntTesta = NULL;
int scelta = -1, ele;
char pausa;

while(scelta!=0) {
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  printf("\t\tESEMPIO UTILIZZO STRUTTURA ASTRATTA: PILA");
  printf("\n\n\n\t\t\t 1. Per inserire un elemento");
  printf("\n\n\t\t\t 2. Per eliminare un elemento");
  printf("\n\n\t\t\t 3. Per visualizzare la pila");
  printf("\n\n\t\t\t 0. Per finire");
  printf("\n\n\n\t\t\t\t Scegliere una opzione: ");
  scanf("%d", &scelta);
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

  switch(scelta) {
    case 1:
       printf("Inserire un elemento: ");
       scanf("%d", &ele);
       puntTesta = inserimento(puntTesta, ele);
       if(puntTesta==NULL) {
         printf("Inserimento impossibile: ");
         printf("memoria disponibile terminata");
         printf("\n\n Premere un tasto per continuare...");
         scanf("%c%c", &pausa, &pausa);
       }
       break;
    case 2:
       if(pilaVuota(puntTesta)) {
         printf("Eliminazione impossibile: pila vuota");
         printf("\n\n Premere un tasto per continuare...");
         scanf("%c%c", &pausa, &pausa);
       }
       else {
         puntTesta = eliminazione(puntTesta, &ele);
         printf("Eliminato: %d", ele );
         printf("\n\n Premere un tasto per continuare...");
         scanf("%c%c", &pausa, &pausa);
       }
       break;
    case 3:
       visualizzazionePila(puntTesta);
       printf("\n\n Premere un tasto per continuare...");
       scanf("%c%c", &pausa, &pausa);
       break;
  }
}
}


void visualizzazionePila(struct elemento *p)
{
struct elemento *paus = p;

printf("\n<------ Testa della pila ");
while(paus!=NULL) {
  printf("\n%d", paus->inf);
  paus = paus->pun;
}
}


struct elemento *inserimento(struct elemento *p, int ele)
{
struct elemento *paus;

paus = (struct elemento *)malloc(sizeof(struct elemento));

if(paus==NULL) return(NULL);

paus->pun = p;
p = paus;
p->inf = ele;
return(p);
}


struct elemento *eliminazione(struct elemento *p, int *ele)
{
struct elemento *paus;

*ele = p->inf;
paus = p;
p = p->pun;
free(paus);
return( p );
}


int pilaVuota(struct elemento *p)
{
if(p==NULL)
  return(1);
else
  return(0);
}
