 
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc,char **argv) { 
    int fd; 
    int bytes_read; 
    char byte;
    
      if( (fd=open(argv[1],O_CREAT)) == -1) exit(1); /*errore,file non aperto*/
          
while ( (bytes_read = read(fd,&byte,1))>0 )
 /* leggo un byte */
{
    
// .... uso il byte letto .....
}

if (bytes_read==-1) exit(1); /* errore in lettura file */

    close(fd);

}
