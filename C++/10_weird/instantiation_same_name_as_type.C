#include <iostream>

class Pippo 
{
protected:
double gi;

public:
int _eta;
Pippo(){};
~Pippo(){};

};






int main() {

Pippo zio;
Pippo Pippo;  ///Allora si puo' chiamare un oggetto di una classe con lo stesso nome della classe!
zio._eta=2;
Pippo._eta=5;
std::cout << "Il risultato e' " << zio._eta <<std::endl;
std::cout << "Il risultato e' " << Pippo._eta <<std::endl;
return 0;
}

