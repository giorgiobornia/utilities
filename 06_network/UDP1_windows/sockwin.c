/* sockwin.c  setup e shutdown dei socket per windows */

#include <stdio.h>

#include <sys/types.h>
#include <errno.h>
#include <io.h>
#include <winsock.h>

/*  per 95
    funzioni winsock dichiarate in winsock.h:
    usare librerie wsock32.lib */

/*  per NT
    funzioni winsock dichiarate in winsock2.h:
    usare librerie ws2_32.lib */

int Init_WinSocket(void) 
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
 
	wVersionRequested = MAKEWORD( 2, 2 );
	err = WSAStartup( wVersionRequested, &wsaData );
	if ( err != 0 ) {
		printf ("WSAStartup failed\n");
		return(0);
	}
	return(1); 
}


void exitWSA( int errorcode) 
{  
   WSACleanup( );
   exit(errorcode);
}


int GetWSASocketError(int sockfd)
{
  int ris, OptVal = 1;
  printf ("setsockopt()\n");
  ris = setsockopt(sockfd, SOL_SOCKET, SO_ERROR, (char *)&OptVal, sizeof(OptVal));
  return(ris);
}
