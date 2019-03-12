/* recvUDP.c   riceve datagram UDP  unicast 
   su SunOS compilare con gcc -o recvUDP -lsocket -lnsl recvUDP.c
   su linux               gcc -o recvUDP recvUDP.c                     */

#include <stdio.h>
#include <sys/types.h>
#include <errno.h>

#include "sockwin.h"

#define SIZEBUF 10000

void usage(void)
{  printf ("usage: recvUDP LOCAL_PORT_NUMBER\n"); exit(1); }

int main(int argc, char *argv[])
{
  struct sockaddr_in Local, From;
  char string_remote_ip_address[100];
  short int remote_port_number, local_port_number;
  int socketfd, OptVal, msglen, Fromlen, ris;
  char msg[SIZEBUF];

  if(argc!=2) { printf ("necessario 1 parametri\n"); usage(); exit(1);  }
  else {
    local_port_number = atoi(argv[1]);
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
  /* indicando INADDR_ANY viene collegato il socket all'indirizzo locale IP     */
  /* dell'interaccia di rete che verrà utilizzata per inoltrare il datagram IP  */
  Local.sin_addr.s_addr	=	htonl(INADDR_ANY);         /* wildcard */
  Local.sin_port		=	htons(local_port_number);
  ris = bind(socketfd, (struct sockaddr*) &Local, sizeof(Local));
  if (ris == SOCKET_ERROR)  {
    printf ("listen() failed, Err: %d \"%s\"  SOCKET_ERROR=%d\n",
		    errno, strerror(errno), GetWSASocketError(socketfd));
    exitWSA(1);
  }

  /* wait for datagram */
  Fromlen=sizeof(struct sockaddr_in);
  msglen = recvfrom ( socketfd, msg, (int)SIZEBUF, 0, (struct sockaddr*)&From, &Fromlen);
  if (msglen<0) {
    printf ("recvfrom() failed, Err: %d \"%s\"  SOCKET_ERROR=%d\n",
		    errno, strerror(errno), GetWSASocketError(socketfd));
    exitWSA(1);
  }
  sprintf((char*)string_remote_ip_address,"%s",inet_ntoa(From.sin_addr));
  remote_port_number = ntohs(From.sin_port);
  printf("ricevuto msg: \"%s\" len %d, from host %s, port %d\n",
          msg, msglen, string_remote_ip_address, remote_port_number);
  exitWSA(1);
  return(0);
}

