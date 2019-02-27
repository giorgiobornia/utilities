#include <cstdio>
#include <string>
using namespace std;
int main ()
{

// char pippo[10];

std::string pippo;
const char* gino=pippo.c_str();  //conversion from 'string' to 'const char*'
char* gigi = (char*) gino;  //casting from 'const char*' to 'char*'
int y = sprintf(gigi,"ciao");
printf("%d\n",y);
return 0;
}