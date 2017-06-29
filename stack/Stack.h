#pragma once

class Stack
{
public:
	struct Item
	{
		Item* next;
		int value;

		Item(int data) : next(nullptr), value(data) {}
	};

private:
	Item* top;

public:
	Stack() :top(nullptr) {}
	~Stack();

	bool isEmpty();
	void clear();

	void push(int data);
	int pop();
	int peek();

	void print();
};
