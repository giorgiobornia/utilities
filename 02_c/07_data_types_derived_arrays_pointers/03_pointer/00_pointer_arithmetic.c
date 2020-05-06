  
  
  
  int n;
  int *p;
  n=100;
  p=&n;
  n=200;
  (*p)++;
  p++;
  p=&n;
  
  
  
// fare il watch delle espressioni &n, n, &p, p, *p
  
  
  
