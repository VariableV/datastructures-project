// Author: Maheen Hussain
#include <vector>
#include <string>
class IntPriorityQueue{
private:
	std::vector<int> heap;
	void swapUp();
	void swapDown();
public:
	IntPriorityQueue();
	void add(int n);
	void pop();
	int peek();
	int size();
	std::string string();
};