#include <iostream>
#include <list>
#include <map>
using namespace std;   //le keyword qui sono evidenziate in nero
#include "cane.H"
#include "levriero.H"
#include "cihuahua.H"

class mymap: public map<const char*, Cane *> {
public:
mymap(){};
~mymap(){};
};

void prova(Cane & cn);
void prova(const mymap &canile);

int main() {
Levriero *Tom; Tom=new Levriero();
Cihuahua *Jerry; Jerry=new Cihuahua();
mymap canile;
canile.insert(make_pair("Tom",Tom));
canile.insert(make_pair("Jerry",Jerry));

prova(canile);

return 0;

}


void prova(Cane & cn) {

cn.abbaia();

}

void prova(const mymap &canile) {
 
// mymap::const_iterator iterb = canile.begin(); 
// mymap::const_iterator itere = canile.end();
mymap::const_iterator iterfind = canile.find("Tom");
cout << " guarda ora sono " << iterfind->first << endl;

//    while( iterb != itere ) {
//      mymap::const_iterator pos = iterb;
//      Cane *canelocale = pos->second;
//      iterb++;
//      cout << " guardami, mi chiamo " << pos->first << endl;
//      canelocale->abbaia();   //overloading dell'operatore *, bello!
//    }

}