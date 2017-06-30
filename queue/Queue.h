#pragma once

#include <stdio.h>

class Queue
{
public:
    struct Item
    {
        Item* next;
        int value;
        
        Item(int data):next(nullptr), value(data) {}
    };
    
private:
    Item* head;
    Item* tail;
    
public:
    Queue() : head(nullptr), tail(nullptr) {}
    ~Queue();
    
    bool isEmpty();
    void clear();
    
    void enqueue(int data);
    int dequeue();
    
    void print();
};
