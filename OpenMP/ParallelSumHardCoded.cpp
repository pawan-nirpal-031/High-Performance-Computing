#include <iostream>
#include <omp.h>
using namespace std; 
const int n = 100000000;
int a[n];

int main(){
  for(int i =0;i<n;i++) a[i] =1;
  double t1 = omp_get_wtime();
  int sum =0;
  int tid,numt;
  #pragma omp parallel default(shared) private(tid)
  {
      tid = omp_get_thread_num();
      numt = omp_get_num_threads();
      int from = (n/numt)*tid;
      int to = (n/numt)*(tid+1)-1;
      if(tid==numt-1) to = n-1;
      int section_sum =0;
      for(int i =from;i<=to;i++) section_sum+=a[i];
      #pragma omp critical
      sum+=section_sum;
  }
  double t2 = omp_get_wtime();
  cout<<"Sum of "<<n<<" elements in "<<(t2-t1)<<" secs the sum is "<<sum<<endl;
  return 0;
}