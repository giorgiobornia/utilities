void giro(char);
void vai(int);

int giaVisitati[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

main()
{
char etichetta, invio;

matAdiacenze();
visMatAdiacenze();
successori();
visita();

/* VISITA A PARTIRE DA UN NODO */
printf("\nImmettere l'etichetta di un nodo: ");
scanf("%c", &invio);
scanf("%c", &etichetta);
giro(etichetta);
}

void giro(char e)
{
int i = 0;
printf("\n");
while(i<n && s[i].inf!=e) i++;
if (i==n) return;
vai(i);
}

void vai(int i)
{
struct successore *p;

p = s[i].pun;
while(p!=NULL) {
  if(giaVisitati[p->inf]==0) {
    giaVisitati[p->inf] = 1;
    printf(" %c", s[p->inf].inf);
    vai( p->inf );
  }
  p = p->pun;
}
}
