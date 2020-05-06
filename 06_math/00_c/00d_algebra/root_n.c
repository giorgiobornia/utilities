 
float rad(int n, float a){
    float appross=0.00001;
    float x=1;
    float pot=1;
    while (valAss(a/pot-x)/n > appross){
	x=((n-1)*x + a/pot)/n;
	pot=pow(x,n-1);
    }
    return x;
}
