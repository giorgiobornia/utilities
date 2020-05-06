#ifndef __cane__
#define __cane__
#include <iostream>
using namespace std;   //perche' mettere questi include qui dentro e non nel .C ? in realta' a me piacerebbe forse di piu' metterli nel C perche' e' li' che vengono usati, cioe' nella implementazione piuttosto che nel prototipo della classe nell'header. Pero' metti che nell'header ci caschi il bisogno di quelle funzioni, allora conviene metterlo nell'header e sai che automaticamente cadra' anche dentro il C.
//Se pero' questo file cane.H non e' chiamato solo dal .C ma anche da altri file (ad esempio il main), allora bisogna stare attenti all'ancora. No non e' vero, se il file .H e' chiamato PRIMA di quando il relativo .C ne abbia bisogno,allora il lavoro per lui e' gia' stato fatto prima e non ci rientra un'altra volta... 
//In questo caso io includo prima del main tutti i file .H che sono inclusi dai tre file .C, quindi non dovrei avere problemi in quanto ho gia' chiamato prima quello che serve ai .C. In realta' non e' cosi'!




class Cane{
public:
int orecchie;
double zampe;

Cane();
~Cane();

virtual void abbaia()=0;  //questa diventa una funzione PURAMENTE VIRTUALE. Formalmente dichiaro che appartiene al padre, ma in realta' appartiene (cioe' viene DICHIARATA e IMPLEMENTATA) solo per i figli del padre; per il padre stesso viene SOLO DICHIARATA come "virtual ... = 0". Pertanto, NON essendo IMPLEMENTATA per il padre, non posso istanziare un oggetto PADRE ! Il padre diventa un "ABSTRACT TYPE".
//Se invece la funzione viene dichiarata "virtual" e basta, allora DEVO IMPLEMENTARLA. Una volta implementata, essa rimane comunque VIRTUALE, quindi per il padre uso la versione del padre, mentre per il figlio, CHE PUR EREDITA TUTTO IL RESTO DAL PADRE, uso la versione del figlio.
//se la funzione invece non e' neppure virtuale, allora direi che non posso ridefinirla anche per i figli, mi darebbe una multiple definition credo... proviamo... No, la posso ridefinire, poi pero' fa del casino...: se passo un figlio ad una funzione che accetta il padre, lei accetta anche i figli del padre, ma lo fa abbaiare come il padre anziche' farlo abbaiare con la sua giovane voce!
//se poi non dichiaro neanche che e' erede, allora non c'e' speranza... a meno che non esistesse il "casting" dalla classe figlio a quella padre, viva la fantasia...:)

};



#endif 
