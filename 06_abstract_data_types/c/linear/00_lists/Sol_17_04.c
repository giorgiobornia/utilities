#include <stdio.h>
#include <malloc.h>

struct elemento {
  int inf;
  struct elemento *pun;
};

void visualizzaLista(struct elemento *);
struct elemento *aggiungi(struct elemento *, struct elemento);

int main()
{
struct elemento *puntPositivi = NULL;
struct elemento *puntNegativi = NULL;
struct elemento x;

do {
  printf("\nInserisci una informazione (0 per fine lista): ");
  scanf("%d", &x.inf);

  if(x.inf>0)
    puntPositivi = aggiungi(puntPositivi, x);
    if(x.inf<0)
      puntNegativi = aggiungi(puntNegativi, x);
}
while(x.inf!=0);

visualizzaLista(puntPositivi);
visualizzaLista(puntNegativi);
}

struct elemento *aggiungi(struct elemento *p, struct elemento x)
{
struct elemento *paus;

if(p==NULL) {
  p = (struct elemento *)malloc(sizeof(struct elemento));
  p->inf = x.inf;
  p->pun = NULL;
}
else {
  paus = (struct elemento *)malloc(sizeof(struct elemento));
  paus->inf = x.inf;
  paus->pun = p;
  p = paus;
}
return(p);
}
