#include <stdio.h>
#include <malloc.h>

struct elemento {
  int inf;
  struct elemento *pun;
};

struct elemento *creaLista2();
void visualizzaLista(struct elemento *);
struct elemento *eliminaPari(struct elemento *);

int main()
{
struct elemento *puntLista;

puntLista = creaLista2();
visualizzaLista(puntLista);

puntLista =  eliminaPari(puntLista);
visualizzaLista(puntLista);
}

struct elemento *eliminaPari(struct elemento *p)
{
struct elemento *paus;
int logica = 1;

while(p!=NULL && logica)
  if(p->inf % 2 == 0)
    p = p->pun;
  else
    logica = 0;

paus = p;
while(paus->pun != NULL)
  if(paus->pun->inf % 2 == 0)
    paus->pun = paus->pun->pun;
  else
    paus = paus->pun;
return(p);
}
