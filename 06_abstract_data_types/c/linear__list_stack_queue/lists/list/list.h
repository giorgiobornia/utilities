#include "element.h"


typedef struct	list_element 
     { element value;
       struct list_element  *next;
     } item;

typedef  item* list;

typedef enum {false, true} boolean;

/*  PROTOTIPI DI FUNZIONE (extern) */

/* PRIMITIVE  */
list emptylist(void);
boolean empty(list);
list cons(element, list);
element head(list);
list tail(list);

/* NON PRIMITIVE */
void showlist(list);
int length(list l);
int length_it(list l);
boolean member(element, list);
boolean member_it(element, list);
list copy (list l);
list delete(element el, list l);
list append (list l1, list l2);
list reverse (list l);
list reverse_tail(list root);
list insord(element el, list l);

