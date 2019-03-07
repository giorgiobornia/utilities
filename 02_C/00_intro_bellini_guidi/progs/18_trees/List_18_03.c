/* Ricerca ottimizzata */

void ricBin(struct nodo *p, int val, struct nodo **pEle)
{
if(p!=NULL)
  if(val == p->inf) {
    printf("  trovato ");
    *pEle = p;
  }
else
  if(val < p->inf) {
    printf("  sinistra");
    ricBin(p->albSin, val, pEle);
  }
  else {
    printf(" destra");
    ricBin(p->albDes, val, pEle);
  }
}
