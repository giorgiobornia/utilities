struct nodo *creaNodo2(struct nodo *p, int val)
{

if(p==NULL) {
  p = (struct nodo *) malloc(sizeof(struct nodo));
  p->inf = val;
  p->occorrenze = 1;
  p->albSin = NULL;
  p->albDes = NULL;
}
else {
  if(val > p->inf)
    p->albDes = creaNodo2(p->albDes, val);
  else
    if(val < p->inf)
      p->albSin = creaNodo2(p->albSin, val);
    else
      ++p->occorrenze;
}
return(p);
}
