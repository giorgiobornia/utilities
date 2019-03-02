/* Memorizza in un file le informazioni passate dall'utente
   sugli alunni di una classe                               */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/* La struttura alunno contiene nome, cognome
   ed età di ogni alunno                      */
struct alunno {
   char nome[100];
   char cognome[100];
   int eta;
};


main()
{
struct alunno alunno;
int nalunni;
int fd;

/* Apre il file alunni */
fd = open("alunni",O_WRONLY|O_CREAT|O_TRUNC,0600);
if(fd < 0) {
   printf("Non posso aprire il file alunni\n");
   exit(1);
}

printf("Quanti alunni vuoi inserire ? ");
scanf("%d",&nalunni);

while(nalunni-- > 0) {
   printf("Nome : ");
   scanf("%s",alunno.nome);
   printf("Cognome : ");
   scanf("%s",alunno.cognome);
   printf("Eta': ");
   scanf("%d",&alunno.eta);
   write(fd, &alunno, sizeof(struct alunno));
}
close(fd);
}
