#include <stdio.h>

 #define N 2
 #define P 1
 #define M 3 


int main()
{

 int i, j, k;

   float mat1[N][P];
   float mat2[P][M];
   float mat3[N][P];
   float mat4[P][M];
   float pma1[N][M];
   float pma2[N][M];
   float srmt[N][M];

   printf("\n \n CARICAMENTO DELLA PRIMA MATRICE \n \n");
 for(i=0; i<N; i++)
   for(j=0; j<P; j++) {
     printf("Inserisci linea %d colonna %d val: \n", i, j);
     scanf("%g", &(mat1[i][j]));
   }  /*i punti e virgola qui in fondo ai cicli sono superflui, non metterli*/ 

 printf("\n \n CARICAMENTO DELLA SECONDA MATRICE \n \n");
 for(i=0; i<P; i++)
   for(j=0; j<M; j++) {
     printf("Inserisci linea %d colonna %d val: \n", i, j);
     scanf("%g", &(mat2[i][j]));
   } 

 printf("\n \n CARICAMENTO DELLA TERZA MATRICE \n \n");
 for(i=0; i<N; i++)
   for(j=0; j<P; j++) {
     printf("Inserisci linea %d colonna %d val: \n", i, j);
     scanf("%g", &(mat3[i][j]));
   }

 printf("\n \n CARICAMENTO DELLA QUARTA MATRICE \n \n");
 for(i=0; i<P; i++)
   for(j=0; j<M; j++) {
     printf("Inserisci linea %d colonna %d val: \n", i, j);
     scanf("%g", &(mat4[i][j]));
   } 

 for(i=0; i<N; i++) 
   for(j=0; j<M; j++) {
     pma1[i][j] = 0.;
     for(k=0; k<P; k++) {  /*c'era un ; che chiudeva il for!*/
       pma1[i][j] += mat1[i][k] * mat2[k][j];}
   }

  
 for(i=0; i<N; i++)
   for(j=0; j<M; j++) {
     pma2[i][j] = 0.;
     for(k=0; k<P; k++) { /*anche qui*/
       pma2[i][j] +=  mat3[i][k] * mat4[k][j];}
   }

 
 for(i=0; i<N; i++)
   for(j=0; j<M; j++) {
     srmt[i][j] = pma1[i][j] + pma2[i][j];
   }

 printf("\n \n PRIMA MATRICE \n ");
 for(i=0; i<N; i++) {
   printf("\n");
   for(j=0; j<P; j++)
     printf("%5g", mat1[i][j]);
 }
 printf("\n \n SECONDA MATRICE \n ");
 for(i=0; i<P; i++) {
   printf("\n");
   for(j=0; j<M; j++)
     printf("%5g", mat2[i][j]);
 }
 printf("\n \n TERZA MATRICE \n ");
 for(i=0; i<N; i++) {
   printf("\n");
   for(j=0; j<P; j++)
     printf("%5g", mat3[i][j]);
 }
 printf("\n \n QUARTA MARICE \n ");
 for(i=0; i<P; i++) {
   printf("\n");
   for(j=0; j<M; j++)
     printf("%5g", mat4[i][j]);
 }
 printf("\n \n MATRICE PRODOTTO E ADDENDO 1 \n");
 for(i=0; i<N; i++) {
   printf("\n");
   for(j=0; j<M; j++)
     printf("%5g", pma1[i][j]);
 }
 printf("\n \n MATRICE PRODOTTO E ADDENDO 2 \n");
 for(i=0; i<N; i++) {
   printf("\n");
   for(j=0; j<M; j++)
     printf("%5g", pma2[i][j]);
 }
 printf("\n \n MATRICE RISULTANTE E FINALE \n");
 for(i=0; i<N; i++) {
   printf("\n");
   for(j=0; j<M; j++)
     printf("%5g", srmt[i][j]);
 }  
 printf("\n");
 return 0;
}