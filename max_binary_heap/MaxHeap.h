#pragma once

class MaxHeap
{
public:
	MaxHeap()
	{
		size = 0;
		heapData = new int[32];
	}
	~MaxHeap() 
	{ 
		delete[] heapData;
		heapData = nullptr;
	}

	void insert(int value);
	int pop();

	int getMax();
	void print();

private:
	int* heapData;
	int size;

	void swap(int indexA, int indexB);
};
