void simmetrico(struct nodo *p)
{
if(p!=NULL) {
  simmetrico(p->albSin);
  printf("\n%d  %d", p->inf, p->occorrenze); 
  simmetrico(p->albDes);                      
}
}
