#include "cane.H"



Cane::Cane(){};
Cane::~Cane(){};

// questa implementazione non serve se la funzione e' puramente virtuale; pero' se la metto il compilatore non mi da' errore, direi che semplicemente la ignora assolutamente, tanto non gli serve. Un warning pero' non guasterebbe per chiarire le cose...

void Cane::abbaia() {

cout << "Io sono un cane" << endl;

}