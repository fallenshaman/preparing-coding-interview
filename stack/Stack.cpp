#include <iostream>
#include "Stack.h"

using namespace std;

Stack::~Stack()
{
	if (isEmpty())
		clear();
}

bool Stack::isEmpty()
{
	return top == nullptr;
}

void Stack::clear()
{
	Item* current = top;
	Item* next = nullptr;

	while (current)
	{
		next = current->next;
		delete current;
		current = next;
	}

	top = nullptr;
}

void Stack::push(int data)
{
	Item* item = new Item(data);
	item->next = top;
	top = item;
}

int Stack::pop()
{
	if (isEmpty())
	{
		cout << "Stack is empty!!" << endl;
		return -1;
	}

	Item* item = top;
	top = item->next;

	int poppedValue = item->value;
	delete item;

	return poppedValue;
}

int Stack::peek()
{
	if (isEmpty())
	{
		cout << "Stack is empty!!" << endl;
		return -1;
	}

	return top->value;
}

void Stack::print()
{
	if (isEmpty())
	{
		cout << "Stack is empty!!" << endl;
	}

	cout << "[TOP] ";
	Item* item = top;

	while (item)
	{
		cout << item->value << " ";
		item = item->next;
	}
	cout << endl;
}
