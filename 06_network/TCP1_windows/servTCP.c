/* servTCP.c   riceve stringa, trasla i caratteri di 2, e 
               rispedisce al mittente
   su SunOS compilare con gcc -o servTCP.c -lsocket -lnsl servTCP.c
   su linux               gcc -o servTCP servTCP.c                   

   eseguire ad esempio su 130.136.2.7 lanciando la seguente riga di comandi:
   servTCP 5001 
   */


#include <stdio.h>
#include <sys/types.h>
// SOLO IN UNIX #include <sys/socket.h>
// SOLO IN UNIX #include <netinet/in.h>
#include <errno.h>

#include <io.h>
#include <winsock2.h>

/*  Winsock Function declared in winsock2.h.
    Link with Library ws2_32.lib.
	 */

int Init_WinSocket(void) 
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
 
	wVersionRequested = MAKEWORD( 2, 2 );
 
	err = WSAStartup( wVersionRequested, &wsaData );
	if ( err != 0 ) {
		/* Tell the user that we could not find a usable */
		/* WinSock DLL.                                  */
		printf ("WSAStartup failed\n");
		return(0);
	}
 
	/* Confirm that the WinSock DLL supports 2.2.*/
	/* Note that if the DLL supports versions greater    */
	/* than 2.2 in addition to 2.2, it will still return */
	/* 2.2 in wVersion since that is the version we      */
	/* requested.                                        */
 
    /*
	if ( LOBYTE( wsaData.wVersion ) != 2 ||
		    HIBYTE( wsaData.wVersion ) != 2 ) {
		WSACleanup( );
		printf ("versione non adatta\n");
		return(0); 
	}
	*/
 
	/* The WinSock DLL is acceptable. Proceed. */
	return(1); 
}

void exitWSA( int errorcode) 
{  
   WSACleanup( );
   exit(errorcode);
}

// SOLO IN UNIX #define SOCKET_ERROR   ((int)-1)
#define SIZEBUF 10000

void usage(void)
{  printf ("usage: servTCP LOCAL_PORT_NUMBER\n"); exit(1); }


int GetWSASocketError(int sockfd)
{
  int ris, OptVal = 1;
  printf ("setsockopt()\n");
  ris = setsockopt(sockfd, SOL_SOCKET, SO_ERROR, (char *)&OptVal, sizeof(OptVal));
  return(ris);
}

int main(int argc, char *argv[])
{
  #define MAXSIZE 100 
  struct sockaddr_in Local, Cli;
  short int local_port_number;
  int socketfd, newsocketfd, OptVal, len, ris;
  int n, nread, nwrite;
  char buf[MAXSIZE];

  if(argc!=2) { printf ("necessario 1 parametri\n"); usage(); exit(1);  }
  else {
    local_port_number = atoi(argv[1]);
  }

  if ( ! Init_WinSocket()   )
	  exitWSA(1);

  /* get a datagram socket */
  printf ("socket()\n");
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd == SOCKET_ERROR) {
    printf ("socket() failed, Err: %d \"%s\"\n", errno,strerror(errno));
    exitWSA(1);
  }

  /* avoid EADDRINUSE error on bind() */
  OptVal = 1;
  printf ("setsockopt()\n");
  ris = setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, (char *)&OptVal, sizeof(OptVal));
  if (ris == SOCKET_ERROR)  {
    printf ("setsockopt() SO_REUSEADDR failed, Errno: %d \"%s\"  SOCKET_ERROR=%d\n",
		    errno,strerror(errno), GetWSASocketError(socketfd));
    exitWSA(1);
  }

  /* name the socket */
  memset ( &Local, 0, sizeof(Local) );
  Local.sin_family		=	AF_INET;
  /* indicando INADDR_ANY viene collegato il socket all'indirizzo locale IP     */
  /* dell'interaccia di rete che verrà utilizzata per inoltrare il datagram IP  */
  Local.sin_addr.s_addr	=	htonl(INADDR_ANY);         /* wildcard */
  Local.sin_port		=	htons(local_port_number);
  printf ("bind()\n");
  ris = bind(socketfd, (struct sockaddr*) &Local, sizeof(Local));
  if (ris == SOCKET_ERROR)  {
    printf ("bind() failed, Err: %d \"%s\"  SOCKET_ERROR=%d\n",
		     errno, strerror(errno), GetWSASocketError(socketfd));
    exitWSA(1);
  }

  printf ("listen()\n");
  ris = listen(socketfd, 10 );
  if (ris == SOCKET_ERROR)  {
    printf ("listen() failed, Err: %d \"%s\"  SOCKET_ERROR=%d\n",
		    errno, strerror(errno), GetWSASocketError(socketfd));
    exitWSA(1);
  }

  
  while(1) {

	/* wait for connection request */
	memset ( &Cli, 0, sizeof(Cli) );
	len=sizeof(Cli);
	printf ("accept()\n");
	fflush(stdout);
	newsocketfd = accept(socketfd, (struct sockaddr*) &Cli, &len);
	printf ("newsocketfd=%d\n", newsocketfd);
	fflush(stdout);
	if (newsocketfd == INVALID_SOCKET)  {
	    printf ("accept() failed, Err: %d \"%s\" SOCKET_ERROR=%d WSAGETLASTERROR=%d\n",
				errno, strerror(errno), GetWSASocketError(socketfd),
				WSAGetLastError());
 		fflush(stderr);
		exitWSA(1);
	}

	/* wait for data */
	nread=0;
	printf ("recv()\n");
	fflush(stdout);
	while( (n=recv(newsocketfd, &(buf[nread]), MAXSIZE ,0 )) >=0) {
		nread+=n;

		printf("\nrecv: ");
		for(n=0;n<nread;n++)
			printf("%c",buf[n]);
		printf("\n");
 		fflush(stdout);

		if(buf[nread-1]=='\0')
			break; /* fine stringa */
    
	}
	if(n<0) {
	    char msgerror[1024];
		sprintf(msgerror,"recv() failed [err=%d SOCKET_ERROR=%d] ",
			    errno, GetWSASocketError(newsocketfd));
		perror(msgerror);
		fflush(stderr);
		exitWSA(1);
	}

	/* traslazione */
	for( n=0; n<nread  -1  ; n++)
		buf[n] = buf[n]+2;

	/* scrittura */
	nwrite=0;
	printf ("send()\n");
	fflush(stdout);
	/* while( (n=write(newsocketfd, &(buf[nwrite]), nread-nwrite)) >=0 ) { */
	while( (nwrite<nread) && ((n=send(newsocketfd, &(buf[nwrite]), nread-nwrite, 0)) >=0) ) {
		nwrite+=n;
		printf("\neseguita send->%d\n", n);
 		fflush(stdout);
	}
	if(n<0) {
		char msgerror[1024];
		sprintf(msgerror,"send() failed [err=%d SOCKET_ERROR=%d] ",
			errno, GetWSASocketError(newsocketfd));
		perror(msgerror);
		fflush(stderr);
		exitWSA(1);
	}

	/* chiusura */
	printf ("close( connected socket)\n");
	fflush(stdout);
	close(newsocketfd);
  
  } /* while(1)  */

  /* chiusura */
  printf ("close()\n");
  fflush(stdout);
  close(socketfd);

  exitWSA(0);
  return(0);
}

