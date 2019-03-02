double pot(double base, int esp)
{
double po;

po = 1;
if(esp == 0)
  return(1);
else {
  while(esp--) po *= base;
  return(po);
}
}
