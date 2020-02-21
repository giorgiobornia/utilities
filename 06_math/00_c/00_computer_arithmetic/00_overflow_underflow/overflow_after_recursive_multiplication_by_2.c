#include <stdio.h>
#include <math.h>

int main() {

/*float*/ double a = 2 * (1 - pow(2,-53));

  while (a < INFINITY) {

  a *= 2;
  
  printf("%.30e\n", a);
  
}

return 0;
}

/*
 * Chiaramente, per partire da un numero ed 
 * avvicinarti a zero non puoi sottrarre una costante
 * ogni volta, perche' andresti nei numeri negativi
 * Quindi, devi dividere per una costante
 * 
 * Piu' piccola e' la costante, piu' lento sara' 
 * l'avvicinamento all'underflow.
 * 
 * ---> Dividendo esattamente per 2, ottengo 
 * esattamente il numero subnormal piu' basso.
 * 
 * ---> Dividendo per un numero maggiore di 2, ottengo
 * un numero maggiore del piu' piccolo numero subnormal
 *       (2^(-126) * 2^(-23) ~ 1e-45,
 * oppure 2^(-1022) * 2^(-52) ~ 1e-324).
 * Se divido per un numero maggiore di 2 e sufficientemente grande,
 * potrei non arrivare ai numeri subnormal e saltare 
 * direttamente dal PIU' PICCOLO NUMERO FLOATING POINT
 * (2^(-126)=1.17549435082e-38 o 2^(-1022)=2.22507385851e-308)
 * allo zero spaccato.
 * (I NUMERI SUBNORMAL si distinguono infatti
 * dai NUMERI FLOATING POINT perche' non sono piu' floating...)
 * Per poter effettuare il salto di cui sopra 
 * bisognerebbe che 126 fosse un multiplo esatto di 23
 * (oppure 1022 un multiplo esatto di 52)... Non e' necessario.
 * Basta scomporre 126 o 1022 in fattori primi  
 * e vedere i fattori...
 * PS: La funzione pow e' software, quindi il compilatore non si 
 * lamenta mai di numeri troppo grandi...
 * 1022 = 2 x 7 x 73
 *  126 = 2 x 3^2 x 7
 * Se dividi per pow(2,73) o pow(2,14) o pow(2,7) allora trovi
 * il piu' piccolo numero floating point ad un certo punto.
 * Pero' non salti direttamente da quello allo zero: cio' succede 
 * se l'esponente che usi per il 2 e' MAGGIORE del numero di cifre 
 * della mantissa (73>52, 511>52, 146>52, ma 14<52, 7<52...) 
 * 
 * ---> AAA Se la costante di divisione e' MINORE di 2 (e MAGGIORE di 1 in modo da poter calare!),
 * ho un comportamento strano, va in loop infinito...
 * Questo avviene perche' la divisione per un numero
 * minore di 2 da' problemi nel range dei numeri subnormal...
 * pow(2,0.001): proviamo ad esempio con 2 ad un esponente minore di 1..
 * 
 * 
 * Ok, questo succedeva con "double", vediamo cosa accade
 * con float, come si comporta il sistema per i numeri subnormal.
 * Con i float abbiamo che il numero floating piu' piccolo e' 1.e-38
 * e il numero subnormal piu' piccolo e' 1.4e-45
 * E infatti dichiarando il tutto come float e dividendo per 2
 * si arriva esattamente a 1.40129846432481707092e-45
 * Ora ricordiamo che 126 = 2 x 3^2 x 7 e dividiamo per alcuni fattori combinati...
 *  Vediamo che 63>23 ma 14<23. E infatti nei casi maggiori di 23 
 * ho il passaggio diretto da minimo floating point a zero.
 * Di nuovo, se il divisore e' MINORE di 2 si blocca e ho un loop infinito...
 * 
 * Ricapitolando:
 * per un'aritmetica floating point a 32 bit
 * min num positivo floating point:          1.17549435082e-38
 * min num positivo subnormal:      1.40129846432481707092e-45
 * 
 * per un'aritmetica floating point a 64 bit
 * min num positivo floating point:   2.225073858507201383090232717332e-308
 * min num positivo subnormal:        4.940656458412465441765687928682e-324
 * 
 * Per quanto riguarda i massimi numeri rappresentabili, 
 * la formula e' 2^(1023) * 2 * (1-(1/2)^53) ~= 2^(1024)
 * ovvero 2^(127) * 2 * (1-(1/2)^24)  ~= 2^(128):
 * tante cifre della mantissa fanno accumulo!
 * 
 * Sappiamo come stampare il piu' piccolo numero rappresentabile (uso "while (a>0.)").
 * E come fare per stampare il piu' grande numero rappresentabile? 
 * Devo fare in modo da avere 1023 nell'esponente e tutti 1 nella mantissa.
 * --> Se moltiplico ad ogni iterazione per 2, aumento correttamente 
 * l'esponente ma mi salto il riempimento della mantissa.
 * Quindi devo moltiplicare per qualcosa di diverso...
 * Dovra' cmq essere sempre MAGGIORE di 1 e MINORE di 2.
 * Se provo con 1.2, 1.1 avro' un riempimento SOLO PARZIALE della mantissa.
 * Se moltiplico per (1+2^(-52))... e' troppo lento...
 * 
 * Ora potrebbero tornare utili i pensieri di prima...
 * Prima avrei potuto pensare, anziche' di DIVIDERE per una COSTANTE,
 * di SOTTRARRE qualcosa di SEMPRE PIU" PICCOLO... pero' come posso sforare
 * se sottraggo qualcosa di sempre piu' piccolo? Non sforerei mai di la'...
 * Allora qui potrei pensare, anziche' di MOLTIPLICARE per una COSTANTE,
 * di SOMMARE una COSTANTE, o qualcosa di sempre piu' grande...
 * I problemi sono:
 * l' addizione e la sottrazione sono molto piu' LENTE!
 * -- l'addizione e' soggetta alla PRECISIONE di MACCHINA che impedisce 
 * di sommare numeri di ordini di grandezza troppo diversi (causa l'arrotondamento)
 * -- la sottrazione e' soggetta alla cancellazione numerica sempre 
 * per l'arrotondamento, se i due numeri sono quasi uguali.
 * 
 * Allora, sembra che lui veda una piccolissima variazione che non gli fa 
 * avere una mantissa PERFETTAMENTE di TUTTI ZERO nel penultimo step... 
 * Quindi allo step dopo riporta un esponente di TUTTI 1 e una mantissa di 
 * NON tutti ZERO... no non credo, altrimenti avrebbe stampato "NaN" anziche' "inf".
 * Cio' significa che e' proprio arrivato in quella situazione! 
 * L'ultima moltiplicazione ha messo TUTTI 1 nell'esponente e tutti zero nella mantissa,
 * che e' appunto la definizione di INF! Quindi, non posso pensare di 
 * continuare a sommare da quel punto in avanti... Devo SOMMARE ALL'INIZIO! 
 * Poi arrivero' ad un NaN forse...
 * No, arriva ad inf, e sembra giungere alla meta corretta! Il fatto e' questo:
 * lui quando vede TUTTI 1 nell'ESPONENTE ha inf.
 * Io ho fatto in modo di riempire PRIMA TUTTA LA MANTISSA di 1, poi 
 * solo all'ultimo passo ho riempito TUTTO L'ESPONENTE di 1. Prima 
 * non avrei potuto evidentemente riempire la mantissa DOPO che 
 * l'esponente era gia' pieno di tutti 1.
 
 


  
 
 */
