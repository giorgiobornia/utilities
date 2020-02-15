struct elemento {
  int inf;
  struct elemento *pun;
};

struct elemento *creaLista2();
void visualizzaLista(struct elemento *);
void contaPari(struct elemento *, int *, int *);
int contaPari2(struct elemento *, int *);

int main()
{
    
int pari, dispari;
struct elemento *puntLista;

puntLista = creaLista2();
visualizzaLista(puntLista);

/* chiamata prima versione di conta pari */
contaPari(puntLista, &pari, &dispari);
printf("\nPari: %d   Dispari: %d", pari, dispari);

/* chiamata seconda versione di conta pari */
printf("\nPari: %d", contaPari2(puntLista, &dispari));
printf("   Dispari: %d\n", dispari);

}

void contaPari(struct elemento *p, int *ppari, int *pdispari)
{
*ppari = *pdispari = 0;

while(p!=NULL) {
  if(p->inf % 2 == 0)
    (*ppari)++;
  else
    (*pdispari)++;
  p = p->pun;
}
}

contaPari2(struct elemento *p, int *pdispari)
{
int pari  = 0;
*pdispari = 0;

while(p!=NULL) {
  if(p->inf % 2 ==0)
    pari++;
  else
    (*pdispari)++;
  p = p->pun;
}
return(pari);
}
