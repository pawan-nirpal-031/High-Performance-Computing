#include <iostream> 
#include <thread> 
using namespace std; 


// a dummy function 
void foo(int z){
	for(int i =0;i<z;i++){
		cout<<"Thread using function pointer as callable\n";
	}
}

// a callable object on thread 
class thobj{
public:
	void opreator()(int x){
		for(int i =0;i<x;i++){
			cout<<"Thread using function object as callable\n";	
		}
	}
};



int main(){
	cout << "Threads 1 and 2 and 3 "
         "operating independently" << endl;
	thread th1(foo,3); 
	thread th2(thobj(),3);  
	th1.join(); 
	th2.join();
	return 0;
}
