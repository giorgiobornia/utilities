 #include <stdio.h>

 
//  A differenza di quanto accade con gli array, il nome della struttura rappresenta la struttura nel suo complesso. Quindi si possono fare assegnazioni tra strutture o realizzare function che hanno per valore una struttura; si può inoltre passare una struttura come parametro a una funzione (passaggio per valore).



typedef struct {float x, y;} punto;	\\ di coordinate (x;y)
typedef struct {float a, b, c;} retta; \\ di equazione ax+by+c=0

punto traslaz(punto, punto);
punto simm(punto,punto);
punto simmAss(punto,retta);
punto rotaz(punto,punto,float);

punto leggiPto();
retta leggiRetta();

main(){ 
	punto P=leggiPto();
	unsigned int op;
	printf("\nTrasformazioni:\n1: traslazione;2\n simmetria centrale;");
	printf("\n3 simmetria assiale:\n4: rotazione;\n\n scelta ?");
	scanf("%d",&op);
	switch (op){
	case1 : 	printf ("Corrispondente di O(0,0) nella traslazione ?");
			punto T=leggiPto();
			P=traslaz(P,T);
			break;
	case2 : 	printf ("Centro di simmetria ?");
			punto S=leggiPto();
			P=simm(P,S);
			break;
	case3 : 	printf ("Asse di simmetria ?");
			asse=leggiRetta();
			P=simmAss(P,asse)
			break;
	case4 : 	printf ("Centro di rotazione ?");
			punto C=leggiPto();
			printf ("\nAngolo di rotazione (rad)?");
			float ang;
			scanf("%f",&ang);
			P=rotaz(P,C,ang);
			break;
	default: ;
	}
	printf("\n\nLe nuove coordinate sono x = %f e y = %f,P.x,P.y);
}

punto leggiPto(){
	punto P;
	printf ("x = ");  scanf("%f",&P.x);
	printf ("y = ");  scanf("%f",&P.y);
	return P
}

punto traslaz(punto P, punto T){
		P.x = P.x + T.x;
		P.y = P.y + T.y;
		return P
}

punto simm(punto P, punto S){
		P.x = 2*S.x - P.x;
		P.y = 2*S.y - P.y;
		return P
}

