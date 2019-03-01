#include <stdio.h>
#include <sys/timeb.h>
#include <mpi.h>
#include <time.h>

char ora[500];

char* GetSysTime ( void )
{
      struct timeb sysTime;
      struct tm *now;

      ftime(&sysTime);
      now = localtime( &sysTime.time );
      sprintf (ora,"%02d:%02d:%02d.%03d", now->tm_hour, 
now->tm_min, now->tm_sec, sysTime.millitm );
return ora;
}

#define TAG 1
#define MAX_SIZE 2
int main(int argc, char**argv)
{
int Error;
int d,d1;
int myid, destinationid,sourceid;
int tasks;
int iter;
int somma=0;
int addendo;
MPI_Request request;
MPI_Status status;
MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD, &myid);
MPI_Comm_size(MPI_COMM_WORLD, &tasks);

destinationid=(myid+1)%tasks;
if (myid==0)
	sourceid=tasks-1;
else
	sourceid=(myid-1)%tasks;
d=myid;
somma=d;
iter=tasks;

while(iter>1)
{
iter--;
MPI_Isend(&d,             /* message buffer */
             1,                 /* data length */
             MPI_INT,           /* data item is an integer */
             destinationid,              /* destination process rank */
             TAG,           /* user chosen message tag */
             MPI_COMM_WORLD, &request);   /* default communicator */
printf("%s I am task %d of %d, I just sent %d  to task %d\n",GetSysTime(),myid,tasks, d,destinationid);

MPI_Recv(&d1,           /* message buffer */
              1,                 /* one data item */
             MPI_INT,        /* of type double real */
             sourceid,    /* receive from any sender */
             TAG,       /* any type of message */
             MPI_COMM_WORLD,    /* default communicator */
             &status);          /* info about the received message */

somma+=d1;
d=d1;
printf("%s I am task %d of %d, I just received %d from task %d. The total is now %d \n",GetSysTime(),myid,tasks, 
d ,sourceid,somma);

}
printf("%s I am task %d of %d, I just finished, the total is  %d\n",GetSysTime(),myid,tasks,somma);

MPI_Finalize();
return 0;
}
