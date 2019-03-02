void immissione(int *pn, int *vet)
{
int i, n;
char invio;

do {
  printf("\nNumero elementi: ");
  scanf("%d", &n);
}
while (n < 1 || n > MAX_ELE);

for(i = 0; i < n; i++) {
  printf("\nImmettere un intero n.%d: ",i);
  scanf("%d", &vet[i]);
}

*pn = n;
}
