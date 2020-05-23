#include<stdio.h>
#include<time.h>
#include<ctype.h>
#include<sys/types.h>
#include<sys/time.h>

// icc temp_gettimeofday.c -o temp_gettimeofday
// ./temp_gettimeofday

// #include <sys/time.h>
// int gettimeofday(struct timeval *restrict tp, void *restrict tzp);


double cclock_()
{
    /* Restituisce il valore del CLOCK di sistema in secondi */
    struct timeval tmp;
    double sec;
    gettimeofday( &tmp, (struct timezone *)0 );
    sec = tmp.tv_sec + ((double)tmp.tv_usec)/1000000.0;
    return sec;
}

int main (int argc, char *argv[]) {
    
double start, finish;

float A[5000][600];

int i,j;

printf("\t\n");

printf("\tUtilizzo di gettimeofday\n");

start = cclock_();

printf("\tSTART = %lf\n",start);

A[0][0]=1.0;

for (i=1;i<600;i++){
	for(j=1;j<5000;j++)
		A[j][i]=(float)(i+j)+A[i-1][j-1];
}

finish = cclock_();
printf("\tEND = %lf\n",finish);
printf("\tTOT = %lf\n",finish-start);
printf("\t\n");

return 0;

}
