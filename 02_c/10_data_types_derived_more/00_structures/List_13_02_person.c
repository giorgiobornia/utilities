#include <stdio.h>
#include <string.h>

#define MAXELE 30
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

/* Vettore persone */
struct per anag[MAXELE];

/* Numero elementi allocati nel vettore anag */
int index = 0;

int menPer(void);
int insPer(int);
struct per * cerPer(char *, char *, int);
void eliPer(struct per *);
void canPer(void);
void ricPer(void);
void visPer(struct per *);
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
      index = insPer(index);
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

/* Inserisce persona nell'anagrafe */
int insPer(int pos)
{
char invio;
if(pos>=MAXELE) {
  printf(" Non si possono inserire altri nomi");
  scanf("%c", &invio);
  return(pos);
}
printf("\n\t\tINSERIMENTO PERSONA");
printf("\n\t\t---------------\n\n");
printf("\nCognome : ");
gets(anag[pos].cognome);
printf("\nNome : ");
gets(anag[pos].nome);
printf("\nIndirizzo : ");
gets(anag[pos].ind);
printf("\nEta' : ");
scanf("%d", &anag[pos].eta);
scanf("%c", &invio);
pos++;
return(pos);
}

/* Cancella persona dall'anagrafe, se presente */
void canPer(void)
{
char pausa;
char cognome[DIM], nome[DIM];
int eta;
struct per *ps;

printf("\n\t\tCANCELLA PERSONA");
printf("\n\t\t------\n\n");
printf("\nCognome : ");
gets(cognome);
printf("\nNome : ");
gets(nome);
printf("\nEta' : ");
scanf("%d", &eta);
scanf("%c", &pausa);
/* invoca ricerca persona */
ps = cerPer(cognome, nome, eta);
if(ps == NULL) {
  printf("\nPersona non presente in anagrafe");
  scanf("%c", &pausa);
  return;
}
/* Invoca visualizza persona */
visPer(ps);
printf("\nConfermi cancellazione ? (S/N) ");
scanf("%c", &pausa);
if(pausa=='S' || pausa=='s') {
  eliPer(ps);
  return;
}
}

/* Elimina persona dall'anagrafe */
void eliPer(struct per *p)
{
strcpy(p->cognome, "");
strcpy(p->nome, "");
strcpy(p->ind, "");
p->eta = 0;
}

/* Ricerca persona se presente nell'anagrafe */
void ricPer(void)
{
char pausa;
char cognome[DIM], nome[DIM];
int eta;
struct per *ps;
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
ps = cerPer(cognome, nome, eta);
if(ps == NULL) {
  printf("\nPersona non presente in anagrafe");
  scanf("%c", &pausa);
  return;
}
visPer(ps);
scanf("%c", &pausa);
}

/* Scansione sequenziale del vettore anag alla ricerca di una
persona che abbia determinati cognome, nome ed età            */
struct per *cerPer(char *cg, char *nm, int et)
{
int i;
for(i=0; i<=index; i++) {
  if(strcmp(cg, anag[i].cognome) == 0)
    if(strcmp(nm, anag[i].nome) == 0)
      if(et == anag[i].eta)
        return(&anag[i]);
}
return(NULL);
}

/* Visualizza persona */
void visPer(struct per *p)
{
printf("\n\n--------------------\n");
printf("\n\t\tCognome : %s", p->cognome);
printf("\n\t\tNome : %s", p->nome);
printf("\n\t\tIndirizzo : %s", p->ind);
printf("\n\t\tEta' : %d", p->eta);
printf("\n\n--------------------\n");
}

/* Visualizza l'anagrafe completa */
void visAnagrafe(void)
{
int i; char pausa;
struct per *ps = &anag[0];
for (i=0; i<index; i++) {
  visPer(ps++);
  scanf("%c", &pausa);
}
}
