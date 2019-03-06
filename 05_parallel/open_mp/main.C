// #define OMP_NUM_THREADS 4  //runtime allocated... has less priority than every other
#include <iostream>
// #include <omp.h>
#include <ctime>
// #include <iomanip>
// #include <fstream>
// #include <cmath>

void parallela();


int main() {
  time_t time_in;
  time( &time_in );   // get the calendar time

// omp_set_num_threads(2);
// #pragma omp parallel 
// {
// std::cout << "thread "<< omp_get_thread_num() << " of " << omp_get_num_threads() << std::endl;
// }
parallela();

  time_t time_out;
  time( &time_out ); 

double delta_t=difftime(time_out,time_in);
std::cout <<'\n'<< delta_t<<'\n';
return 0;
}