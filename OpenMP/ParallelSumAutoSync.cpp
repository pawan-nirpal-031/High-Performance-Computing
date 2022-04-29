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
  #pragma omp parallel default(shared)
  {
      int section_sum =0;
      #pragma omp for
      for(int i =0;i<n;i++) section_sum+=a[i];
      #pragma omp critical
      sum+=section_sum;
  }
  double t2 = omp_get_wtime();
  cout<<"Sum of "<<n<<" elements in "<<(t2-t1)<<" secs the sum is "<<sum<<endl;
  return 0;
}