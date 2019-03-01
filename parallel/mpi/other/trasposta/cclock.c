#include<sys/types.h>
#include<sys/time.h>


double cclock_()
{

    /* Restituisce il valore del CLOCK di sistema in secondi */

    struct timeval tmp;
    double sec;
    gettimeofday( &tmp, (struct timezone *)0 );
    sec = tmp.tv_sec + ((double)tmp.tv_usec)/1000000.0;
    return sec;

}
