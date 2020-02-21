/*for every function here i may put
 * BOTH the derivative
 * AND a primitive
 * so that i may use the same file for both integrals and zeros!
  */

#define PI  3.14159265359




#if MYFUNC == 1
 #define        FUNC(x)    4.*sin(x) + 1. - x 
#define   FPRIMITIVE(x)  - 4.*cos(x) + x - x*x / 2.   
#define FDERIVATIVE(x)     4.*cos(x) -1.
#define X_A 1.5  
#define X_B 4.0 
#endif


#if MYFUNC == 2
#define        FUNC(x)     exp(-x) - x - 5. 
#define  FPRIMITIVE(x)  - ( exp(-x) + x*x/2. + 5.*x)
#define FDERIVATIVE(x)    -exp(-x) - 1. 
#define X_A -3.  
#define X_B 3. 
#endif


#if MYFUNC == 3
#define        FUNC(x)    (x+1.)* exp(x/4.) - 2. 
#define FPRIMITIVE(x)  4.*(x-3.)*exp(x/4.) - 2.*x   
#define FDERIVATIVE(x)     exp(x/4.)  +  (x+1.)*exp(x/4.)/4. 
#define X_A -3.  
#define X_B 3. 
#endif


#if MYFUNC == 4
#define        FUNC(x)    x*x*x*x/4. - 2.*x*x*x + x*x - 5.*x + 8. 
#define FPRIMITIVE(x)  x*x*x*x*x/20. - x*x*x*x/2. + x*x*x/3. - 5.*x*x/2. + 8.*x   
#define FDERIVATIVE(x)     x*x*x - 6.*x*x + 2.*x - 5. 
#define X_A -2.  
#define X_B 4. 
#endif

#if MYFUNC == 5
 #define        FUNC(x)    3.*cos(x) + 2 - x*x/2.
#define FPRIMITIVE(x)  3.*sin(x) + 2.*x - x*x*x/6.   
#define FDERIVATIVE(x)   -3.*sin(x) - x
#define X_A 0.  
#define X_B 3.5 
#endif


#if MYFUNC == 6
#define        FUNC(x)    exp(x) - x*x + x 
#define FPRIMITIVE(x)   exp(x) - x*x*x/3. + x*x/2.  
#define FDERIVATIVE(x)     exp(x) - 2.*x + 1.
#define X_A -3.  
#define X_B 3. 
#endif


#if MYFUNC == 7
#define        FUNC(x)    x*x + 8.*sin(3.*x/4.) + x - 5.   
#define FPRIMITIVE(x)  x*x*x/3. - 32.*cos(3.*x/4.)/3. + x*x/2. - 5.*x
#define FDERIVATIVE(x)  2.*x + 6.*cos(3.*x/4.) + 1.
#define X_A -1.  
#define X_B 3. 
#endif


#if MYFUNC == 8
/* Attenzione questo sembra non andare bene con la correzione dei trapezi!
 * E sembra anche non andare bene con Simpson!
 * Il fatto e' che l'integrale e' ESATTO per questa funzione con questi metodi...
 * Forse e' la SIMMETRIA dell'intervallo che crea problemi...
 * No, non basta rimuovere la simmetria!
 * Se io rimuovo la simmetria
 * e metto una funzione non polinomiale (quindi l'integrale non e' esatto)
 * continua a non darmi la convergenza
 * Se io rimuovo la simmetria
 * e metto una funzione polinomiale di grado 9 (quindi l'integrale non e' esatto)
 * allora mi da' la convergenza!
 * Se io MANTENGO la simmetria
 * e metto una funzione polinomiale di grado 9 (quindi l'integrale non e' esatto)
 * allora DI NUOVO NON MI DA' LA CONVERGENZA!
 * Consideriamo allora la perturbazione alla funzione del 3 ordine:
 * Se l'intervallo e' simmetrico e la perturbazione e' una funzione DISPARI (x^9),
 * allora il suo  contributo all'integrale e' NULLO e ricadiamo nel caso
 * del 3 ordine;
 * Se l'intervallo e' simmetrico e la perturbazione e' una funzione PARI (x^8),
 * il suo contributo non dovrebbe essere nullo...
 * Se l'intervallo e' simmetrico e la perturbazione e' una funzione NE' PARI NE' DISPARI,
 * ancora il suo contributo non dovrebbe essere nullo...
 * 
 * PERCHE' la funzione +(x-1)*sin(x) NON VA?
 * 
 * Quindi sembra esserci un legame tra l'ordine di convergenza e il grado
 * di precisione che a prima vista mi sembravano separati...
 * In realta' son la stessa cosa! Dici che un metodo e' del 
 * 4 ordine se nello sviluppo dell'errore il termine dominante
 * e' del 4 ordine. 
 * Ovviamente > e' l'ordine e piu' il metodo e' PRECISO;
 * ma precisione significa al tempo stesso VELOCITA',
 * cioe' se uso quel metodo per raffinare arrivo piu'
 * velocemente ad una stessa tolleranza! Chiaro, l'errore
 * per una stessa suddivisione e' piu' piccolo in un caso!
 */
#define        FUNC(x)    x*x*x - x*x/2. + 2.*x + 1.   + exp(x) /*+(x-1)*sin(x)        */   /* +    x*x*x*x*x*x*x*x      */
#define FPRIMITIVE(x)  x*x*x*x/4. - x*x*x/6. + x*x + x + exp(x) /*-(x-1)*cos(x) +cos(x)*/   /* +    x*x*x*x*x*x*x*x*x/9. */
#define FDERIVATIVE(x)   3.*x*x - x + 2.               + exp(x) /*+sin(x) +(x-1)*cos(x)*/   /* +    x*x*x*x*x*x*x*8.     */
#define X_A -2.  
#define X_B 2. 
#endif


#if MYFUNC == 9
#define        FUNC(x)     exp(x/3.) + 4.*sin(x/2.) - 2. + x   
#define  FPRIMITIVE(x)  3.*exp(x/3.) - 8.*cos(x/2.) - 2.*x + x*x/2.
#define FDERIVATIVE(x)    1./3.*exp(x/3.) + 2.*cos(x/2.) + 1.
#define X_A -3.
#define X_B 4. 
#endif


#if MYFUNC == 10
#define        FUNC(x)    x*x*x - 2.*cos(x) - x - 20.   
#define FPRIMITIVE(x)  x*x*x*x/4. - 2.*sin(x) - x*x/2. - 20.*x   
#define FDERIVATIVE(x)    3.*x*x + 2.*sin(x) - 1.
#define X_A 1.  
#define X_B 4. 
#endif


#if MYFUNC == 11
#define        FUNC(x)    3.*x*exp(-x/4.) - cos(x)   
#define  FPRIMITIVE(x)  -12.*(4. + x)*exp(-x/4.) - sin(x)
#define FDERIVATIVE(x)   3.*exp(-x/4.) -  3.*x*exp(-x/4.)/4.  + sin(x)
#define X_A -2.  
#define X_B 2. 
#endif


#if MYFUNC == 12 
/*PERICOLOSA!!
 * Il metodo delle secanti va in palla per questa funzione
 * perche' e' PARI!
 * e noi partiamo con un intervallo SIMMETRICO RISPETTO ALLO ZERO!
 * (fa-fb) fa zero!
 * Ora mettiamo un intervallo NON SIMMETRICO rispetto a zero!
 * Comunque rimane il problema che ho dato una funzione 
 * che ha PIU' DI UNO ZERO all'interno dell'intervallo considerato!
 * Diamola nonsimmetrica...
 * E' chiaro che noi inizialmente diamo una funzione in un intervallo
 * ma la nostra delimitazione ad un intervallo e' puramente convenzionale;
 * la radice alla generica iterazione n potra' cadere anche ALL'ESTERNO
 * di tale intervallo. Noi individuiamo un intervallo perche' 
 * partiamo dal fatto di sapere che c'e' UNA SOLA radice in quell'intervallo
 * e vorremmo SPERABILMENTE arrivare a QUELLA e non ad altre...
 * ma NON E' SEMPRE DETTO !
 * 
 * Adesso e' successo che la funzione va bene 
 * con il metodo della secante ma non va piu' bene
 * con il metodo della tangente!
 * Sostanzialmente ho sostituito 3.*x con 3.*x*x
 * Conta molto anche il fatto di cominciare da xa anziche' da xb
 * Faccio 3.*x*x*x tra 0 e 2 e sono spiccio

*/
#define        FUNC(x)    3.*x*x*x  - 4.*cos(3.*x/2.) -1.
#define  FPRIMITIVE(x)   3.*x*x*x*x/4. - (8./3.)*sin(3.*x/2.) - x   
#define FDERIVATIVE(x)   9.*x*x  +6.*sin(3.*x/2.) 
#define X_A 0.  
#define X_B 2. 
#endif


#if MYFUNC == 13
/* This function is quite oscillatory for the SECANT method
 * 15 iterations are not enough to get to convergence!
 * What is interesting is to notice what happens by changing
 the MAXIMUM number of iterations */
#define        FUNC(x)     exp(x) + x*x/2. + PI/2. * cos( PI * x/2.) - 6.  
#define FPRIMITIVE(x)     exp(x)  + x*x*x/6.  +   sin( PI * x/2.) -6.*x
#define FDERIVATIVE(x)     exp(x) + x  - PI*PI/4. * sin( PI * x/2.)
#define X_A -1.  
#define X_B 3. 
#endif




#if MYFUNC == 14
/* This function is quite oscillatory for the SECANT method
 * 15 iterations are not enough to get to convergence!
 * What is interesting is to notice what happens by changing
 the MAXIMUM number of iterations */
 #define        FUNC(x)     exp(x) + x - PI/2. * sin( PI*x/2.) -5.
#define FPRIMITIVE(x)   exp(x) + x*x/2. + cos( PI*x/2.)  -5.*x
#define FDERIVATIVE(x)      exp(x) + 1. - PI*PI/4. * cos( PI*x/2.)
#define X_A -1.  
#define X_B 4. 
#endif

/*Ok, quindi ho modificato le funzioni 8 e 12 e per ora non uso
le funzioni 13 e 14*/
