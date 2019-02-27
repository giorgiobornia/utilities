///Templates
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;



///template class




///template function

template <class T>
T maximum(T t1, T t2)
{
if (t1 > t2)
{
return t1;
}
return t2;
}


template <class T,class G>
class Pippo
{public:


T gino;
G pino;
};


int main(int argc, char* pArgs[])
{
Pippo<double,double> ffifi;
ffifi.gino= 7.;
ffifi.pino= 19.;


cout << "The value is" << ffifi.gino << endl;
// find the maximum of two int’s
cout << "The maximum of 1 and 2 is " << maximum(1, 2) << endl;
// repeat for two doubles
cout << "The maximum of 1.5 and 2.5 is " << maximum(1.5, 2.5) << endl;
// system("PAUSE"); questo e' per Windows
return 0;
}
