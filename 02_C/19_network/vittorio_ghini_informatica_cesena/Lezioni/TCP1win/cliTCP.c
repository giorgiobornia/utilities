/* cliTCP.c    spedisce stringa, riceve stringa traslata
   su SunOS compilare con gcc -o cliTCP.c -lsocket -lnsl cliTCP.c
   su linux               gcc -o cliTCP cliTCP.c                   

   eseguire ad esempio su 137.204.72.49 lanciando la seguente riga di comandi
   cliTCP 130.136.2.7 5001 
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
 
/*	if ( LOBYTE( wsaData.wVersion ) != 2 ||
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
{  printf ("usage: cliTCP REMOTE_IP_NUMBER REMOTE_PORT_NUMBER\n");
   exit(1);
}

int main(int argc, char *argv[])
{
  #define MAXSIZE 100 
  struct sockaddr_in Local, Serv;
  char string_remote_ip_address[100];
  short int remote_port_number;
  int OptVal, ris;
  int socketfd;
  int n, nread, nwrite, len;
  char buf[MAXSIZE];
  char msg[]="012345ABCD";

  if(argc!=3) { printf ("necessari 2 parametri\n"); usage(); exit(1);  }
  else {
    strncpy(string_remote_ip_address, argv[1], 99);
    remote_port_number = atoi(argv[2]);
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
    printf ("setsockopt() SO_REUSEADDR failed, Err: %d \"%s\"\n", errno,strerror(errno));
    exitWSA(1);
  }

  /* name the socket */
  memset ( &Local, 0, sizeof(Local) );
  Local.sin_family		=	AF_INET;
  /* indicando INADDR_ANY viene collegato il socket all'indirizzo locale IP     */
  /* dell'interaccia di rete che verrà utilizzata per inoltrare i dati          */
  Local.sin_addr.s_addr	=	htonl(INADDR_ANY);         /* wildcard */
  Local.sin_port	=	htons(0);
  printf ("bind()\n");
  ris = bind(socketfd, (struct sockaddr*) &Local, sizeof(Local));
  if (ris == SOCKET_ERROR)  {
    printf ("bind() failed, Err: %d \"%s\"\n",errno,strerror(errno));
    exitWSA(1);
  }

  /* assign our destination address */
  memset ( &Serv, 0, sizeof(Serv) );
  Serv.sin_family	 =	AF_INET;
  Serv.sin_addr.s_addr  =	inet_addr(string_remote_ip_address);
  Serv.sin_port		 =	htons(remote_port_number);

  /* connection request */
  printf ("connect()\n");
  ris = connect(socketfd, (struct sockaddr*) &Serv, sizeof(Serv));
  if (ris == SOCKET_ERROR)  {
    printf ("connect() failed, Err: %d \"%s\"\n",errno,strerror(errno));
    exitWSA(1);
  }

  /* scrittura */
  len = strlen(msg)+1;
  nwrite=0;
  printf ("send()\n");
  
  while	( (len>nwrite) && ((n=send(socketfd, &(msg[nwrite]), len-nwrite, 0))>=0)  )
     nwrite+=n;
  if(n<0) {
     char msgerror[1024];
     sprintf(msgerror,"write() failed [err %d] ",errno);
     perror(msgerror);
	 exitWSA(1);
  }

  /* lettura */
  nread=0;
  printf ("recv()\n");
  while( (n=recv(socketfd, &(buf[nread]), len-nread, 0 )) >=0) {
     nread+=n;
  
  	 printf("\nrecv %d: ", n);
	 for(n=0;n<nread;n++)
		 printf("%c\n",buf[n]);
	 printf("\n");
 	 fflush(stdout);
     if(buf[nread-1]=='\0')
        break; /* fine stringa */
  }
  
  if(n<0) {
    char msgerror[1024];
    sprintf(msgerror,"read() failed [err %d] ",errno);
    perror(msgerror);
	exitWSA(1);
  }
  
  /* stampa risultato */
  printf("stringa traslata: %s\n", buf);

  /* chiusura */
  close(socketfd);

  exitWSA(0);
}

