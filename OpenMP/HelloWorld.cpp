#include <iostream>
#include "omp.h"
using namespace std;

int main(){
  int num_t;
  int tid;
  #pragma omp parallel 
  {
    num_t = omp_get_num_threads();
    tid = omp_get_thread_num();
    cout<<"\n Hello form thread "<<tid<<" of "<<num_t;
  }   
  return 0;
}