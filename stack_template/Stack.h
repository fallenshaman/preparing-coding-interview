#pragma once

template<typename T>
class Stack
{
public:

	struct Item
	{
		Item* next;
		T value;

		Item(T data) : next(nullptr), value(data) {}
	};

private:
	Item* top;

public:
	Stack() :top(nullptr) {}
	~Stack()
	{
		if (isEmpty())
			clear();
	}

	bool isEmpty() 
	{
		return top == nullptr;
	}

	void clear()
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

	void push(T const & data) 
	{
		Item* item = new Item(data);
		item->next = top;
		top = item;
	}

	T pop()
	{
		if (isEmpty())
		{
			throw out_of_range("Stack is empty!");
		}

		Item* item = top;
		top = item->next;

		int poppedValue = item->value;
		delete item;

		return poppedValue;
	}

	T peek()
	{
		if (isEmpty())
		{
			throw out_of_range("Stack is empty!");
		}

		return top->value;
	}

	void print()
	{
		if (isEmpty())
		{
			throw out_of_range("Stack is empty!");
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
};
