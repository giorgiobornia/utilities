 
float potR(float x, int n){
  return (n>0)? x*potR(x,n-1) : 1;
}
