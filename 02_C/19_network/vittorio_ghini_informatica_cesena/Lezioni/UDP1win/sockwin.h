/* sockwin.h  setup e shutdown dei socket per windows */

#ifndef __SOCKWIN_H__
#define __SOCKWIN_H__


#include <sys/types.h>
#include <winsock.h>

/*  per 95
    funzioni winsock dichiarate in winsock.h:
    usare librerie wsock32.lib */

/*  per NT
    funzioni winsock dichiarate in winsock2.h:
    usare librerie ws2_32.lib */

extern int Init_WinSocket(void) ;
extern void exitWSA( int errorcode) ;
extern int GetWSASocketError(int sockfd);


#endif


/*  */



