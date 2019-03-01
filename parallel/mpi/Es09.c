/*
 *    It evolves the equation:
 *                            u,t + u,x + u,y = 0
 *    Using a Lax scheme.
 *    The initial data is a cruddy gaussian.
 *    Boundaries are flat: copying the value of the neighbour
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>
#include <string.h>
#define NX 150
#define NY 150
#define LX 2.0
#define LY 2.0

#define MASTER 0

#define sigma 0.1
#define tmax 100

/* conversions from discrete to real coordinates: can be better */
float ix2x(int ix){
    float dx=LX/NX;
    return ix*dx;//-LX/2;
 
}

/*
 * THIS CHANGES: the every processor has a different offset
 * I pass also the proc_y and I do not use proc_me directy because
 * saving the file I use this parameter to evaluate the real y coordinate
 * for all the data of other processors that are saved by 0 however.
 */

float iy2y(int iy, int NLY, int proc_y){ 
	int size=NY/NLY;
	float spessoresingoloprocesso=LY/size;
    	float dy=LY/NY;
    	return iy*dy+spessoresingoloprocesso*proc_y; 

}

/* 
 * initialize the system with a gaussian temperature distribution 
 */

int init_transport(float *temp, int NLY, int proc_me){
    
    int ix,iy;
    float x,y;

    for(iy=1;iy<NLY+1;++iy)
	for(ix=1;ix<NX+1;++ix){	
	    x=ix2x(ix);
	    y=iy2y(iy, NLY, proc_me);
   	    x=x-LX/2;
	    y=y-LY/2;
	    temp[((NX+2)*iy)+ix] = tmax*exp((-((x*x)+(y*y)))/(2.0*(sigma*sigma)));
	    //temp[((NX+2)*iy)+ix] = ((float)proc_me)*0.1 + ix+100*iy;
	}
    return 0;
}

void SaveBlockData(FILE *file, float *temp, int NLY, int proc_me)
{
	int r,c;
	for(r=0;r<NLY;r++){
		for(c=1;c<NX+1;c++)
			fprintf(file,"%f %f %f \n",ix2x(c),iy2y(r+1, NLY, proc_me),temp[r*(NX+2)+c]);
		//fprintf(file,"\n\n");
	}

} 



void PrintBlockData(float *temp, int NLY)
{
return ;
	int r,c;
	for(r=0;r<NLY;r++){
		for(c=1;c<NX+1;c++)
			printf("%f ",temp[r*(NX+2)+c]);
		printf("\n\n");
	}

} 
/*
 * save the temperature distribution
 * the ascii format is suitable for splot gnuplot function
 */

int save_gnuplot(char *filename, float *temp, int NLY, int proc_me, int nprocs){
if(proc_me==MASTER){
	MPI_Status status;
	int k;
float *temp_new;
	FILE *file;
	float tempextern;
	temp_new=(float*)malloc(sizeof(float)*NLY*(NX+2));

	file=fopen(filename,"w+");
	SaveBlockData(file,&temp[NX+2],NLY,MASTER);/*for myself, MASTER*/
	for (k=1;k<nprocs;k++){
		memset(temp_new,0,sizeof(float)*NLY*(NX+2));
		MPI_Recv(temp_new, NLY*(NX+2), MPI_FLOAT, k, k, MPI_COMM_WORLD,&status);
		printf("-----sono il master, ho ricevuto %d dati da %d\n",NLY*(NX+2),k);
		PrintBlockData(temp_new,NLY);
		SaveBlockData(file,temp_new,NLY,k);/*from k*/
	}
	free((void*)temp_new);
	fclose(file);
}
else{
    /*
     * All processors send to proccesor 0 their section of array temp.
     */
	
	printf("sono il task %d, mando % d dati a 0\n",proc_me,NLY*(NX+2));
	PrintBlockData(&temp[NX+2],NLY);
	MPI_Send(&temp[NX+2],NLY*(NX+2),MPI_FLOAT,MASTER,proc_me, MPI_COMM_WORLD);
}


    return 0;
}

int update_boundaries_FLAT(float *temp, int NLY, int nprocs, int proc_me, int proc_up, int proc_down){

    MPI_Status status;
    int iy=0, ix=0;
    
    for(iy=1;iy<=NLY;++iy){
	temp[(NX+2)*iy] = temp[((NX+2)*iy)+1];
	temp[((NX+2)*iy)+(NX+1)] = temp[((NX+2)*iy)+NX];
    }
if(MPI_PROC_NULL!=proc_down){
/*sono il primo, scambio solo con quella in basso sotto di me*/
	MPI_Sendrecv(&temp[(NX+2)*(NLY+2)-2*(NX+2)],NX+2,MPI_FLOAT,proc_down,1,
	             &temp[(NX+2)*(NLY+2)-  (NX+2)],NX+2,MPI_FLOAT,proc_down,1, MPI_COMM_WORLD,&status);
}

if(MPI_PROC_NULL!=proc_up){
/*sono il primo, scambio solo con quella in basso sotto di me*/
	MPI_Sendrecv(&temp[NX+2],NX+2,MPI_FLOAT,proc_up,1,
	             &temp[0],NX+2,MPI_FLOAT,proc_up,1, MPI_COMM_WORLD,&status);
}
    return 0;
}


int evolve(float dtfact, float *temp, float *temp_new, int NLY){
    
    float dx, dt;
    int ix, iy;
    float temp0;
    
    dx = 2*LX/NX;
    dt = dtfact*dx/sqrt(3.0);
    
    for(iy=1;iy<=NLY;++iy)
	for(ix=1;ix<=NX;++ix){
	    temp0 = temp[((NX+2)*iy)+ix];
	    temp_new[((NX+2)*iy)+ix] = 
temp0-0.5*dt*(temp[((NX+2)*(iy+1))+ix]-temp[((NX+2)*(iy-1))+ix]+temp[((NX+2)*iy)+(ix+1)]-temp[((NX+2)*iy)+(ix-1)])/dx;
	}
    
    for(iy=0;iy<NLY+2;++iy)
	for(ix=0;ix<NX+2;++ix)
	    temp[((NX+2)*iy)+ix] = temp_new[((NX+2)*iy)+ix];
    
    return 0;
}


int main(int argc, char* argv[]){
float totale=0;
    int nprocs, proc_me, proc_up, proc_down;

    int i=0, NLY;
    float *temp, *temp_new;


    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &proc_me);

/*  
 *  all the communications from/to MPI_PROC_NULL do nothing
 */

    proc_down = proc_me+1;
    proc_up = proc_me-1;

    if(proc_up < 0)
	proc_up = MPI_PROC_NULL;

    if(proc_down == nprocs) proc_down = MPI_PROC_NULL;

    NLY = NY/nprocs;
    
    temp = (float *) malloc ((NX+2)*(NLY+2)*sizeof(float));
    memset(temp,0,(NX+2)*(NLY+2)*sizeof(float));
    temp_new = (float *) malloc ((NX+2)*(NLY+2)*sizeof(float));

    init_transport(temp, NLY, proc_me);


    update_boundaries_FLAT(temp, NLY, nprocs, proc_me, proc_up, proc_down);

    save_gnuplot("transport.dat", temp, NLY, proc_me, nprocs);
   

    for(i=1;i<=1200;++i){
	evolve(0.1, temp, temp_new, NLY);
	update_boundaries_FLAT(temp, NLY, nprocs, proc_me, proc_up, proc_down);
    }
    
    save_gnuplot("transport_end.dat", temp, NLY, proc_me, nprocs);   


//MPI_Reduce(&temp[NX+2],&totale,NLY*(NX+2), MPI_FLOAT,MPI_SUM,0,MPI_COMM_WORLD);
//printf("sono il %d e la media vale %f\n", proc_me,totale/nprocs);
 

MPI_Finalize();
    return 0;

}

