#pragma once

#include <stdio.h>


class Queue_CircularArray
{
private:
    static const int MAX_SIZE = 10;
    int data[MAX_SIZE];
    
    int front;
    int rear;
    
public:
    Queue_CircularArray() : front(-1), rear(-1) {}
    
    bool isEmpty();
    bool isFull();
    
    void clear();
    
    void enqueue(int value);
    int dequeue();
    
    int count();
    
    void print();
};
