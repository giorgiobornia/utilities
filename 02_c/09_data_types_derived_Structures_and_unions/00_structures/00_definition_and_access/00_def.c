#include <stdio.h>


int main() {
    
//     type definition
   struct luogo {
 char nome[30];
int x;
int y;
int z;
};

struct luogo monte_bianco; //instantiation


//     type definition with instantiations
struct luogo2 {
char nome[30];
int x;
int y;
int z;
} monte_bianco2 , monte_rosa2;

//     type definition with instantiations but without struct name (not needed in other places)

struct {
char nome[30];
int x;
int y;
int z;
} monte_bianco3 , monte_rosa3;

//     type definition with typedef
typedef struct {
char nome[30];
int x;
int y;
int z;
} LUOGO;

LUOGO milano; //no need for the struct keyword anymore

//     type definition with both identifiers: type name and with typedef

typedef struct luogo3 {
    
 char nome[30];
 int x;
 int y;
 int z;
 
} LUOGO3;

struct luogo3 Cesena;
LUOGO3  Cesenatico;

//Initialization of struct

LUOGO3 City = {"home", 1, 5, 8 };

     return 0;
  
}
