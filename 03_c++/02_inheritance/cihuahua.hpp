#ifndef __cihuahua__
#define __cihuahua__
#include "cane.H"
#include <iostream>
using namespace std;


class Cihuahua : public Cane {  //bastava mettere public per la classe base... non e' che si puo' mettere un public una volta sola scritto quando dichiaro la classe Cane? proviamo... naah... se lo fai dichiarare al padre diventa public per tutto il codice, se invece lo fai dire a ciascun figlio diventa public solo per i figli. Come se il padre dicesse a tutto il mondo SARETE MIEI EREDI, oppure i singoli figli andassero a chiedere al padre VOGLIO ESSERE TUO EREDE, e il padre tacitamente annuisse.
public:
Cihuahua();
~Cihuahua();

void abbaia();
};

#endif

