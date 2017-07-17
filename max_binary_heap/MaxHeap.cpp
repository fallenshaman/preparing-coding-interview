#include <iostream>

#include "MaxHeap.h"

using namespace std;

void MaxHeap::insert(int value)
{
	int currentPos = size++;

	heapData[currentPos] = value;

	int parentIndex = (currentPos - 1) / 2;

	while( parentIndex >= 0 && heapData[parentIndex] < heapData[currentPos]  )
	{
		swap(parentIndex, currentPos);

		currentPos = parentIndex;
		parentIndex = (currentPos - 1) / 2;
	}
}


int MaxHeap::pop()
{
	if (size == 0)
	{
		cout << "Heap is empty!" << endl;
		return -1;
	}

	int maxValue = heapData[0];

	// Move last value at index 0
	heapData[0] = heapData[size - 1];
	size--;

	int root = 0;
	
	while (root < size)
	{
		int left = (root * 2) + 1;
		int right = left + 1;


		if (left >= size)		// no children
			break;			
		else if (right >= size)	// only left child
		{
			if (heapData[left] > heapData[root])
			{
				swap(root, left);
				root = left;
			}
			else
				break;		
		}
		else
		{
			// children exist both side
			if (heapData[left] > heapData[root] && heapData[right] > heapData[root])
			{
				if (heapData[left] > heapData[right])
				{
					swap(left, root);
					root = left;
				}
				else
				{
					swap(right, root);
					root = right;
				}
			}
			else if (heapData[left] > heapData[root])
			{
				swap(left, root);
				root = left;
			}
			else if (heapData[right] > heapData[root])
			{
				swap(right, root);
				root = right;
			}
			else
				break;
		}
	}

	return maxValue;
}

int MaxHeap::getMax()
{
	if (size == 0)
	{
		cout << "Heap is empty!" << endl;
		return -1;
	}

	return heapData[0];
}


void MaxHeap::swap(int indexA, int indexB)
{
	int temp = heapData[indexA];
	heapData[indexA] = heapData[indexB];
	heapData[indexB] = temp;
}

void MaxHeap::print()
{
	for (int i = 0; i < size; ++i)
	{
		cout << heapData[i] << " ";
	}
	cout << endl;
}
