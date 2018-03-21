// Author: Maheen Hussain
#include "IntPriorityQueue.h"

// traverse up the heap swapping the smallest element, used for add when adding a new node to the tree
void IntPriorityQueue::swapUp(){
	int last=heap.size()-1;
	while(last>0){
		int parent = (last-1)/2;
		if (heap.at(parent) > heap.at(last)){
			int tmp=heap.at(parent);
			heap.at(parent)=heap.at(last);
			heap.at(last)=tmp;
			last=parent;
		}
		else{
			break;
		}
	}
}

// traverse down the heap, finding the smallest element to swap current root with, used for remove
void IntPriorityQueue::swapDown(){
	int elem=0;
	while(elem < heap.size()){
		int min=-1, left=elem*2+1, right=elem*2+2;
		if (left < heap.size()){
			min = (min==-1) ? left : (std::min(heap.at(left), heap.at(min)) == heap.at(left)) ? left : min;
			if (right < heap.size()){
				min = (std::min(heap.at(left), heap.at(right))==heap.at(left)) ? left : right;	
			}
		}
		else{
			break;
		}
		if (heap.at(min) < heap.at(elem)){
			int tmp=heap.at(elem);
			heap.at(elem)=heap.at(min);
			heap.at(min)=tmp;
			elem=min;
		}
		else{
			break;
		}
	}
}

IntPriorityQueue::IntPriorityQueue() : heap(){
}

// add 'n' to the end of the queue, then figuring out placement in the heap
void IntPriorityQueue::add(int n){
	heap.push_back(n);
	swapUp();
}

// remove the root of the heap, find the new root
void IntPriorityQueue::pop(){
	heap.at(0)=heap.at(heap.size()-1);
	heap.erase(heap.begin()+heap.size()-1);
	swapDown();
}

// view the root
int IntPriorityQueue::peek(){
	return heap.at(0);
}

// get size of heap
int IntPriorityQueue::size(){
	return heap.size();
}

// method to view the elements in heap
std::string IntPriorityQueue::string(){
	std::string str="";
	for(int i = 0; i < heap.size(); i++){
		str += std::to_string(heap.at(i)) + " ";
	}
	return str.substr(0, str.length()-1);
}