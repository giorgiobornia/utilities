#include <stdio.h>
#include <stdlib.h>



int main()
{
  FILE* foutp;
  
  foutp = fopen("file.out","a");
 /* foutp = fopen("file.out","r");*/
 /* foutp = fopen("file.out","r+");*/
 /* foutp = fopen("file.out","w");*/
/*  foutp = fopen("file.out","w+");*/
/*  foutp = fopen("file.out","a");*/
/*  foutp = fopen("file.out","a+");*/
  
  if(foutp == NULL)
  {
    fprintf(stderr,"Errore nell'apertura del file\n");
    return 36;
  }
  
  printf("Riga1:xxx \n");
  printf("riga2:xxx yyy\tzzz");
  printf("\nriga3:xxx\byyy\n");
  printf("riga4:xxx\fyyy\n");
  printf("riga5:xxx\vyyy\n");
  printf("riga6:xxx\r");
  printf("riga7:xxx\n\n");
  printf("riga8:xxx\nriga9:xxx\tyyy\bzzz\nriga10:xxx\fyyy\vzzz\nriga11\rriga12:END");
  
  fprintf(foutp,"Riga1:xxx \n");
  fprintf(foutp,"riga2:xxx yyy\tzzz");
  fprintf(foutp,"\nriga3:xxx\byyy\n");
  fprintf(foutp,"riga4:xxx\fyyy\n");
  fprintf(foutp,"riga5:xxx\vyyy\n");
  fprintf(foutp,"riga6:xxx\r");
  fprintf(foutp,"riga7:xxx\n\n");
  fprintf(foutp,"riga8:xxx\nriga9:xxx\tyyy\bzzz\nriga10:xxx\fyyy\vzzz\nriga11\rriga12:END");
  
 
  fclose(foutp);

    return 0;

}

/*Difference between various states
 
     r      Open text file for reading.  
           The stream is positioned at the beginning of the file.

       r+     Open  for  reading  and  writing.
              The stream is positioned at the beginning of the file.

       w      Truncate file to zero length or create text file for writing.
             The stream is  positioned at the beginning of the file.

       w+     Open  for reading and writing.
             The file is created if it does not exist, otherwise it is truncated.
             The stream is positioned at the beginning of the file.

       a      Open for appending (writing at end of file).
              The file is created if  it  does  not exist.
              The stream is positioned at the end of the file.

       a+     Open for reading and appending (writing at end of file).
              The file is created if it does not exist.
              The initial file position for reading is at the beginning  of  the
              file, but output is always appended to the end of the file.

    (r,r+) errore se non c'è il file ===
    (w,w+,a,a+) no errore se non c'è il file ===

PER SCRIVERE
  w VS r+: il primo non dà errore, il secondo si'
PER LEGGERE
  r VS w+: il primo dà errore, il secondo no
PER APPENDERE
 a,a+: nessuno dà errore
  Attenzione quando dovete girare un programma tante volte, fareste file immensi!
  
  La norma e':
  usate -un file SOLO per leggere
        -un ALTRO file SOLO per scrivere
  r+ e w+ servono per fare ENTRAMBE le cose su un SINGOLO FILE, piu' complesso.
  r+ ha bisogno di un file già esistente.
            Puoi leggere cose già scritte, e aggiungere delle cose.
  w+ no, anzi CANCELLA il file se già esistente.
            Puoi scrivere, e leggere quello che hai scritto.
  
  r VS r+: con r le fprintf sono semplicemente IGNORATE
           con r+ le fprintf sono invece ESEGUITE
           Questo cambia il comportamento di una successiva fscanf
  
 */

/*  fscanf(foutp,"%c",&c);
  printf("Ho stampato : %c :\n",c);*/

/* Alcuni caratteri speciali:

       \\     backslash

       \a     alert (BEL)

       \b     backspace

       \c     produce no further output

       \e     escape

       \f     form feed

       \n     new line

       \r     carriage return

       \t     horizontal tab

       \v     vertical tab  */