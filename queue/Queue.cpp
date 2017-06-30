#include "Queue.h"
#include <iostream>

using namespace std;

Queue::~Queue()
{
    if(!isEmpty())
        clear();
}

bool Queue::isEmpty()
{
    return head == nullptr && tail == nullptr;
}

void Queue::clear()
{
    Item* current = head;
    Item* next = nullptr;
    while(current)
    {
        next = current->next;
        delete current;
        current = next;
    }
    
    head = nullptr;
    tail = nullptr;
}

void Queue::enqueue(int data)
{
    Item* item = new Item(data);
    
    // first enqueue
    if(isEmpty())
    {
        head = item;
        tail = item;
    }
    else
    {
        tail->next = item;
        tail = item;
    }
}

int Queue::dequeue()
{
    if(isEmpty())
    {
        cout << "Queue is empty." << endl;
        return -1;
    }
    
    // head에서 아이템 제거
    
    Item* item = head;
    int value = item->value;
    
    head = head->next;
    
    if(head == nullptr) // dequeue last item
        tail = nullptr;
    
    delete item;
    
    return value;
}

void Queue::print()
{
    if(isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    
    Item* current = head;
    
    while(current)
    {
        if(current == head)
            cout << " H";
        cout << current->value;
        if(current == tail)
            cout << "T";
        
        cout << " ";
        current = current->next;
    }
    cout << endl;
}
