 
char f(char c){
  char cc;
  if (c>='a' && c<='z') cc = c - ('a'-'A');
  if (c>='A' && c<='Z') cc = c + 'a'-'A';
  return cc;
}
