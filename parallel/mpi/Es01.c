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


int main(int argc, char**argv)
{
int Error;
int myid, otherid;
int tasks;
MPI_Status status;
MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD, &myid);
MPI_Comm_size(MPI_COMM_WORLD, &tasks);
#define TAG 1

if(myid==0){
/*master*/
MPI_Send(&myid,             /* message buffer */
             1,                 /* one data item */
             MPI_INT,           /* data item is an integer */
             1,              /* destination process rank */
             TAG,           /* user chosen message tag */
             MPI_COMM_WORLD);   /* default communicator */
printf("%s I am task %d of %d, I just sent my id to task 1\n",GetSysTime(),myid,tasks);

MPI_Recv(&otherid,           /* message buffer */
             1,                 /* one data item */
             MPI_INT,        /* of type double real */
             1,    /* receive from any sender */
             TAG,       /* any type of message */
             MPI_COMM_WORLD,    /* default communicator */
             &status);          /* info about the received message */
 printf("%s I am task %d of %d, I just received id= %d  from task 1\n",GetSysTime(),myid,tasks, otherid);

}

else if(myid==1){
/*slave*/

MPI_Recv(&otherid,           /* message buffer */
             1,                 /* one data item */
             MPI_INT,        /* of type double real */
             0,    /* receive from any sender */
             TAG,       /* any type of message */
             MPI_COMM_WORLD,    /* default communicator */
             &status);          /* info about the received message */
 printf("%s I am task %d of %d, I just received id= %d  from task 0\n",GetSysTime(),myid,tasks, otherid);


MPI_Send(&myid,             /* message buffer */
             1,                 /* one data item */
             MPI_INT,           /* data item is an integer */
             0,              /* destination process rank */
             TAG,           /* user chosen message tag */
             MPI_COMM_WORLD);   /* default communicator */
printf("%s I am task %d of %d, I just sent my id to task 0\n",GetSysTime(),myid,tasks);

}
else
printf("%s I am task %d of %d, but I shouldn't be running!!!!!\n",GetSysTime(),myid,tasks);

MPI_Finalize();
return 0;
}
