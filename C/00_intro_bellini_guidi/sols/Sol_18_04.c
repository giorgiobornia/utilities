void differito(struct nodo *p)
{
struct nodo *paus = p;
paus = paus->pArco;

printf("(");
while(paus!=NULL) {
  differito(paus->figlio);
  paus = paus->pArco;
}
printf("%c)", p->inf);
}
