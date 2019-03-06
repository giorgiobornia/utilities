#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mpi.h>
#define MASTER 0


void GeneraBlocco(int *Blocco,int numrighe,int numcolonne, int rank, int offset)
{
int r;
int c;

memset(Blocco,0,numrighe*numcolonne*sizeof(Blocco[0]));
for (r=0;r<numrighe;r++)
	if(r*numcolonne+r+offset<numrighe*numcolonne)
		Blocco[r*numcolonne+r+offset]=1;
printf("fine memset");
}

void ScriviBlocco(FILE* file,int *Blocco,int numrighe,int numcolonne)
{
int r;
int c;
printf("scrivo %d x %d\n", numrighe, numcolonne);
for(r=0;r<numrighe;r++){
	for(c=0;c<numcolonne;c++)
		fprintf(file,"%d ",Blocco[r*numcolonne+c]);
	fprintf(file,"\n");
}
printf("fine scrivi");

}


#define TOTAL_SIZE 15
int main(int argc, char** argv)
{

int Size;
int MyId;
int numcolonne;
int numrighe;
int *Blocco;
int resto;
int offset;
FILE *file;
MPI_Status Status;
MPI_Init(&argc,&argv);
MPI_Comm_size ( MPI_COMM_WORLD ,&Size );
MPI_Comm_rank ( MPI_COMM_WORLD ,&MyId );
numcolonne= TOTAL_SIZE;
numrighe=TOTAL_SIZE/Size;
resto=TOTAL_SIZE-numrighe*Size;

if(MyId>=Size-resto)
{
	numrighe++;
	offset=MyId*numrighe-(Size-resto);
}
else
	offset=MyId*numrighe;
Blocco=(int*)malloc(sizeof(int)*numcolonne*(numrighe+1));/*alloco pi\ grande*/

printf("Sono il processo %d, ho %d righe\n",MyId, numrighe);

GeneraBlocco(Blocco,numrighe,numcolonne,MyId,offset);
if(MyId==MASTER){
	/*open the file*/
	int k=1;
	FILE* file;
	/*file=fopen("matrice.txt","w");*/
file=stdout;
	/*write my own data*/
	ScriviBlocco(file,Blocco,numrighe,numcolonne);
	/*receive all the data, in order*/
	while(k<Size){
printf("ascolto %d",k);
		numrighe=TOTAL_SIZE/Size;
		resto=TOTAL_SIZE-numrighe*Size;
		if(k>=Size-resto)
			numrighe++;
		MPI_Recv(Blocco,numrighe*numcolonne,MPI_INTEGER,k,1,MPI_COMM_WORLD, &Status);
		ScriviBlocco(file,Blocco,numrighe,numcolonne);
printf("fine ascolto %d",k);
k++;
	}
	/*close the file*/
	/*fclose(file);*/
}

else	{
printf("slave, inizio spedizione");
MPI_Send(Blocco,numrighe*numcolonne,MPI_INTEGER, MASTER,1,MPI_COMM_WORLD);
printf("slave, fine spedizione");
}

free(Blocco);
MPI_Finalize();
printf("Il processo %d  e' stato chiuso\n",MyId);
return 0;
}
