#include <iostream> 
#include <chrono>
#include <thread>
#include <vector>
#include <unistd.h> 
using namespace std;

void cpu_waster(){
    cout<<"Cpu waster process id : "<<getpid()<<endl; 
    cout<<"Cpu waster thread id : "<<std::this_thread::get_id()<<endl;
    while(1) continue; 
}

int main(){
    cout<<"main process id : "<<getpid()<<endl; 
    cout<<"main thread id : "<<std::this_thread::get_id()<<endl;
    std::thread thread1(cpu_waster); 
    std::thread thread2(cpu_waster); 
    while(1){
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
