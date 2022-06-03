#include <iostream> 
#include <thread> 

bool chopping = 1;

void vegetable_chopper(const char* name){
	unsigned int vegtable_count =0; 
	while(chopping) vegtable_count+=1; 
	printf("%s chopped %u vegetables\n",name,vegtable_count); 
}

int main(){
	std::thread person1(vegetable_chopper,"person 1"); 
	std::thread person2(vegetable_chopper,"person 2");
	printf("both have begun chopping veges...\n"); 
	std::this_thread::sleep_for(std::chrono::seconds(1)); 
	chopping = 0; 
	person1.join(); 
	person2.join();
	return 0;
}
