#include "Queue_CircularArray.h"

#include <iostream>

using namespace std;


bool Queue_CircularArray::isEmpty()
{
    return front == -1 && rear == -1;
}

bool Queue_CircularArray::isFull()
{
    return (rear + 1) % MAX_SIZE == front;
}

void Queue_CircularArray::clear()
{
    front = -1;
    rear = -1;
}

void Queue_CircularArray::enqueue(int value)
{
    if(isFull())
    {
        cout << "Queue is full" << endl;
        return;
    }
    
    if(isEmpty())
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX_SIZE;
    }
    
    data[rear] = value;
}

int Queue_CircularArray::dequeue()
{
    if(isEmpty())
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    
    int value = data[front];
    
    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX_SIZE;
    }
    
    return value;
}

int Queue_CircularArray::count()
{
    if(isEmpty())
        return 0;
    
    return ( (rear + MAX_SIZE - front) % MAX_SIZE ) + 1;
}

void Queue_CircularArray::print()
{
    if(isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    
    int itemCount = count();
    int index = front;
    for(int i =0; i< itemCount; ++i)
    {
        cout << data[index] << " ";
        
        index++;
        
        if(index >= MAX_SIZE)
            index = index % MAX_SIZE;
    }
    cout << endl;
}

