/* LIST IMPLEMENTATION - file list.c */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* OPERAZIONI PRIMITIVE */
list  emptylist(void)		/* costruttore lista vuota */
{ return NULL; }

boolean  empty(list l)	/* verifica se lista vuota */
{ if (l==NULL) return true;
	else return false; }

list  cons(element e, list l)
{ list t;       /* costruttore che aggiunge in testa alla lista */
  t=(list)malloc(sizeof(item));
  t->value=e;
  t->next=l;
  return(t);
}

element  head(list l) /* selettore testa lista */
{ if (empty(l)) abort();
  else return (l->value); 
}

list  tail(list l)         /* selettore coda lista */
{ if (empty(l)) abort();
  else return (l->next); 
}



/* OPERAZIONI NON PRIMITIVE */


/*  ATTENZIONE:  la showlist() e' definita solo per element di tipo int  */
void   showlist(list l)
{ /* VERSIONE ITERATIVA: */
  printf("[");
  while (!empty(l)) 
          { printf("%d",head(l));
	      l=tail(l);
	      if (!empty(l)) printf(", "); 
          }
  printf("]\n");
}


int	length(list l)     /* Lunghezza di una lista (ricorsiva) */
{ if (empty(l)) return(0);
  else return 1+length(tail(l));
}

int	length_it(list l)  /* Lunghezza di una lista (iterativa) */
{ int n=0;
  while (!empty(l))
	 { n++; 
          l=tail(l); }
  return(n);
}


boolean member(element el, list l)
/* appartenenenza di un elemento - ricorsiva  */
{ if (empty(l)) return false;
  else { if (el==head(l)) return true;
	  else return member(el,tail(l)); }
}

boolean member_it(element el,list l)
/* appartenenenza di un elemento - iterativa  */
{ while (!empty(l))
	  { if (el==head(l)) return true;
           else  l= tail(l); }
  return false;
}


list copy (list l)
/* crea una copia della lista l */
{ if (empty(l)) return l;
  else return cons(head(l),copy(tail(l)));
}

list delete(element el, list l)
{ if (empty(l)) return emptylist();
  else {if (el==head(l)) return tail(l);
	 else return cons(head(l),delete(el,tail(l))); }
}

list	append (list l1, list l2)
{ /* concatenamento di liste - ricorsiva          */
 if (empty(l1)) return l2;
  else return cons(head(l1),append(tail(l1),l2));
}


list reverse (list l)
{ /* inversione di una lista - ricorsiva          */
  if (empty(l)) return emptylist();
  else return append(reverse(tail(l)),
			cons(head(l),emptylist()));
}


list rev(list l2, list l1)
{/* funzione ausiliaria */
 if  (empty(l1)) return l2;
 else return rev(cons(head(l1),l2),tail(l1)); 
}


list reverse_tail(list l)
{ /* inversione di una lista - tail ricorsiva      */
  return rev(emptylist(),l);}

/*  ATTENZIONE:  la insord() e' definita solo per element di tipo int  */
list insord(element el, list l) {
  if (empty(l)) return cons(el,l);
  else if (el <= head(l)) return cons(el,l);
  else return cons(head(l), insord(el,tail(l)));
}
