#include <stdio.h>
#include <string.h>

#define DIM    31
#define MENU    0
#define INS     1
#define CAN     2
#define RIC     3
#define VIS     4
#define OUT   100

/* Semplice struttura che modella una persona */
struct per {
  char cognome[DIM];
  char nome[DIM];
  char ind[DIM];
  int  eta;
};

/* Puntatore al file */
FILE *fp;

/* La variabile di appoggio anag per le operazioni
sul file    								      */
struct per anag;

int menPer(void);
void insPer(void);
void ricPer(void);
void canPer(void);
long cerPer(char *, char *, int);
void eliPer(long pos);
void visPer(void);
void visAnagrafe(void);

/* Presenta il menu e lancia la funzione scelta */
void main()
{
int scelta = MENU;
while(scelta!=OUT) {
  switch(scelta) {
    case MENU:
      scelta = menPer();
      if(scelta == MENU)
         scelta = OUT;
      break;
    case INS:
      insPer();
      scelta = MENU;
      break;
    case CAN:
      canPer();
      scelta = MENU;
      break;
    case RIC:
      ricPer();
      scelta = MENU;
      break;
  case VIS:
      visAnagrafe();
      scelta = MENU;
      break;}
}
}

/* Menu */
int menPer(void)
{
int scelta;
char invio;
int vero = 1;

while(vero){
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  printf("\t\t\t ANAGRAFE");
  printf("\n\n\n\t\t\t 1. Immissione Persona");
  printf("\n\n\t\t\t 2. Cancellazione Persona");
  printf("\n\n\t\t\t 3. Ricerca Persona");
  printf("\n\n\t\t\t 4. Visualizza anagrafe");
  printf("\n\n\t\t\t 0. Fine");
  printf("\n\n\n\t\t\t\t Scegliere una opzione: ");
  scanf("%d", &scelta);
  scanf("%c", &invio);
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  switch(scelta) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      return(scelta);
    default:
      break;
  }
}
return(0);
}

/* Inserisce persona nel file anag.dat */
void insPer(void)
{
char invio;
/* Se il file non esiste lo crea,
   i dati sono appesi in fondo al file   */
fp = fopen("anag.dat","a+");

printf("\n\t\tINSERIMENTO PERSONA");
printf("\n\t\t---------------\n\n");
printf("\nCognome : ");
gets(anag.cognome);
printf("\nNome : ");
gets(anag.nome);
printf("\nIndirizzo : ");
gets(anag.ind);
printf("\nEta' : ");
scanf("%d", &anag.eta);
scanf("%c", &invio);

fwrite(&anag, sizeof(struct per), 1, fp);
fclose(fp);
}

/* Cancella una persona dall'anagrafe, se presente */
void canPer(void)
{
char pausa;
char cognome[DIM], nome[DIM];
int eta;
long pos;
printf("\n\t\tCANCELLA PERSONA");
printf("\n\t\t------\n\n");
printf("\nCognome : ");
gets(cognome);
printf("\nNome : ");
gets(nome);
printf("\nEta' : ");
scanf("%d", &eta);
scanf("%c", &pausa);
/* Invoca ricerca persona */
pos = cerPer(cognome, nome, eta);
if(pos == -1) {
  printf("\nPersona non presente in anagrafe");
  scanf("%c", &pausa);
  return;
}
/* Invoca visualizza persona */
visPer();
printf("\nConfermi cancellazione ? (S/N) ");
scanf("%c", &pausa);
if(pausa=='S' || pausa=='s') {
  eliPer(pos);
  return;
}
}

/* Elimina persona dall'anagrafe */
void eliPer(long pos)
{
strcpy(anag.cognome, "");
strcpy(anag.nome, "");
strcpy(anag.ind, "");
anag.eta = 0;
fp = fopen("anag.dat","r+");
fseek(fp,pos,0);
fwrite(&anag, sizeof(struct per), 1, fp);
fclose(fp);
}

/* Ricerca persona */
void ricPer(void)
{
char pausa;
char cognome[DIM], nome[DIM];
int eta;
long pos;
/* Inserimento dati persona da ricercare */
printf("\n\t\tRICERCA PERSONA");
printf("\n\t\t------\n\n");
printf("\nCognome : ");
gets(cognome);
printf("\nNome : ");
gets(nome);
printf("\nEta' : ");
scanf("%d", &eta);
scanf("%c", &pausa);
/* Invoca la funzione di scansione sequenziale */
pos = cerPer(cognome, nome, eta);
if(pos == -1) {
  printf("\nPersona non presente in anagrafe");
  scanf("%c", &pausa);
  return;
}
visPer();
scanf("%c", &pausa);
}

/* Effettua una scansione sequenziale del file anag.dat
   alla ricerca di una persona che abbia determinati cognome,
   nome ed età                                               */
long cerPer(char *cg, char *nm, int et)
{
int n;
long pos = 0L;

fp = fopen("anag.dat", "r");

for(;;) {
  n = fread(&anag, sizeof(struct per), 1, fp);
  if(n==0) {
    fclose(fp);
    pos = -1;
    return (pos);
  }
  else
    if(strcmp(cg, anag.cognome) == 0)
      if(strcmp(nm, anag.nome) == 0)
        if(et == anag.eta) {
	      pos = ftell(fp);
		  fclose(fp);
          return(pos-sizeof(struct per));
	    }
  }
}

/* Visualizza persona */
void visPer(void)
{
printf("\n\n--------------------\n");
printf("\n\t\tCognome : %s", anag.cognome);
printf("\n\t\tNome : %s", anag.nome);
printf("\n\t\tIndirizzo : %s", anag.ind);
printf("\n\t\tEta' : %d", anag.eta);
printf("\n\n--------------------\n");
}

/* Visualizza l'anagrafe completa */
void visAnagrafe(void)
{
int n; char pausa;
fp = fopen("anag.dat", "r");
do {
  n = fread(&anag, sizeof(struct per), 1, fp);
  if(n==0) fclose(fp);
  else {
    visPer();
    scanf("%c", &pausa);
  }
}
while(n!=0);
}
