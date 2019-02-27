#include <iostream>
using namespace std;

class Base
{
       public:
          Base(){ cout<<"Constructor: Base"<<endl;}
          virtual ~Base(){ cout<<"Destructor : Base"<<endl;}
          //if the Base destructor is virtual,
	  // then both the Derived and the Base destructors are called
	  //otherwise, only the Base destructor is called
};

class Derived: public Base
{
     //Doing a lot of jobs by extending the functionality
       public:
           Derived(){ cout<<"Constructor: Derived"<<endl;}
           ~Derived(){ cout<<"Destructor : Derived"<<endl;}
 };
 
 
int main()
{
        Base *Var = new Derived();
        delete Var;
return 0;
}