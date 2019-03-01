#include <omp.h>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <cmath>

#ifndef N_STEPS
#define N_STEPS 10000
#endif
// #define OMP_NUM_THREADS 4 
//non va bene

void parallela(){

std::ofstream out("pluto"); 
int tid;
// omp_set_num_threads(8);

//qui inizia la biforcazione
#pragma omp parallel
{
std::cout << "n. threads: " << omp_get_num_threads() << std::endl;
}
#pragma omp parallel for private(tid)
  for (int i=1;i<N_STEPS;i++)
{
 tid = omp_get_thread_num();

    out << tid <<'|'<< std::setw(10) << (int)( 0.5 + sqrt(i)*sqrt(i) ) << '|' << std::endl;
  }
}