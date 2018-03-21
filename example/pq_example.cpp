// Author: Maheen Hussain
#include "..\src\IntPriorityQueue\IntPriorityQueue.h"
#include <iostream>

// for example 2
void heapsort(std::vector<int>& vec){
	IntPriorityQueue pqueue;
	int i;
	for(i = 0; i < vec.size(); i++){
		pqueue.add(vec.at(i));
	}
	for(i=0; i < vec.size(); i++){
		vec.at(i)=pqueue.peek();
		pqueue.pop();
	}
}

int main(){
	// example 1 usage, minimum heap
	IntPriorityQueue pqueue;
	pqueue.add(2);
	pqueue.add(1);
	std::cout << pqueue.string() << std::endl;
	// example 2 usage, heap sort implementation
	std::vector<int> tosort={5,4,3,2,1};
	heapsort(tosort);
	for(int i = 0; i < tosort.size(); i++){
		std::cout << tosort.at(i) << " ";
	}
	return 0;
}