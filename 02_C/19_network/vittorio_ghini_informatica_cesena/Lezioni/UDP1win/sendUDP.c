/* sendUDP.c   spedisce datagram UDP  unicast 
   su SunOS compilare con gcc -o sendUDP -lsocket -lnsl sendUDP.c
   su linux               gcc -o sendUDP sendUDP.c                  */

#include <stdio.h>
#include <sys/types.h>
#include <errno.h>

#include "sockwin.h"

void usage(void) 
{  printf ("usage: sendUDP MESSAGE REMOTE_IP_NUMBER\n");
   exit(1);
}

int main(int argc, char *argv[])
{
  struct sockaddr_in Local, To;
  char string_remote_ip_address[100];
  short int remote_port_number;
  int socketfd, OptVal, addr_size;
  int ris;

  if(argc!=3) { printf ("necessari 2 parametri\n"); usage(); exit(1);  }
  else {
    strncpy(string_remote_ip_address, argv[1], 99);
    remote_port_number = atoi(argv[2]);
  }

  if ( ! Init_WinSocket()   )
	  exitWSA(1);

  /* get a datagram socket */
  socketfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (socketfd == SOCKET_ERROR) {
    printf ("socket() failed, Err: %d \"%s\"\n", errno,strerror(errno));
    exitWSA(1);
  }

  /* avoid EADDRINUSE error on bind() */ 
  OptVal = 1;
  ris = setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, (char *)&OptVal, sizeof(OptVal));
  if (ris == SOCKET_ERROR)  {
    printf ("setsockopt() SO_REUSEADDR failed, Errno: %d \"%s\"  SOCKET_ERROR=%d\n",
		    errno,strerror(errno), GetWSASocketError(socketfd));
    exitWSA(1);
  }


  /* name the socket */
  Local.sin_family		=	AF_INET;
  /* si lega il socket all'indirizzo IP dell'interfaccia che verrà usata per inoltrare il datagram IP  */
  Local.sin_addr.s_addr	=	htonl(INADDR_ANY);
  /* 0 come porta, il s.o. decide lui  a quale porta UDP collegare il socket */
  Local.sin_port		=	htons(0); /* il s.o. decide la porta locale */
  ris = bind(socketfd, (struct sockaddr*) &Local, sizeof(Local));
  if (ris == SOCKET_ERROR)  {
    printf ("listen() failed, Err: %d \"%s\"  SOCKET_ERROR=%d\n",
		    errno, strerror(errno), GetWSASocketError(socketfd));
    exitWSA(1);
  }

  /* assign our destination address */
  To.sin_family	 =	AF_INET;
  To.sin_addr.s_addr  =	inet_addr(string_remote_ip_address);
  To.sin_port		 =	htons(remote_port_number);

  addr_size = sizeof(struct sockaddr_in);
  /* send to the address */
  ris = sendto(socketfd, argv[1], strlen(argv[1]) , 0, (struct sockaddr*)&To, addr_size);
  if (ris < 0) {
    printf ("sendto() failed, Err: %d \"%s\"  SOCKET_ERROR=%d\n",
		    errno, strerror(errno), GetWSASocketError(socketfd));
    exitWSA(1);
  }
  else
     printf("datagram UDP \"%s\" sent to (%s:%d)\n",
             argv[1], string_remote_ip_address, remote_port_number);

  return(0);
}
