void differito(struct nodo *p)
{
if(p!=NULL) {
  differito(p->albSin);
  differito(p->albDes);
  printf("%d  ", p->inf);
}
}
