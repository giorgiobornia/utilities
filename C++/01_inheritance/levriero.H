#ifndef __levriero__
#define __levriero__
#include "cane.H"
#include <iostream>
using namespace std;


class Levriero :public Cane {
public:

  typedef Cane Parent;

Levriero();
~Levriero();

void abbaia();
};

#endif

