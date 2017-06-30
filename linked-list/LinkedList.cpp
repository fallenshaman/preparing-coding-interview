#include "LinkedList.h"
#include <iostream>

using namespace std;


LinkedList::~LinkedList()
{
    if(head)
        clear();
}

int LinkedList::size(){
    int count = 0;
    
    Node* currentNode = head;
    
    while(currentNode)
    {
        currentNode = currentNode->next;
        count++;
    }
    
    return count;
}

bool LinkedList::isEmpty() { return head == nullptr; }

void LinkedList::clear()
{
    Node* currentNode = head;
    Node* nextNode = nullptr;
    
    while(currentNode)
    {
        nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
    
    head = nullptr;
    tail = nullptr;
}

void LinkedList::pushFront(int value)
{
    Node* newNode = new Node(value);
    
    newNode->next = head;
    head = newNode;
    
    // first value
    if(tail == nullptr)
        tail = newNode;
}

int LinkedList::popFront()
{
    if(isEmpty())
    {
        cout << "[ERROR] List is empty!!" << endl;
        return -1;
    }
    
    Node* poppedNode = head;
    int value = poppedNode->data;
    
    head = poppedNode->next;
    
    // last node popped
    if(tail == poppedNode)
        tail = head;
    
    delete poppedNode;
    
    return value;
}

void LinkedList::pushBack(int value)
{
    Node* newNode = new Node(value);
    
    // first value add
    if(tail == nullptr)
    {
        tail = newNode;
        head = tail;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

int LinkedList::popBack()
{
    if(isEmpty())
    {
        cout << "List is empty!!" << endl;
        return - 1;
    }
    
    Node* currentNode = head;
    Node* prevNode = nullptr;
    
    while (currentNode->next) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    
    // list has more than one node.
    if(prevNode != nullptr)
    {
        prevNode->next = nullptr;
    }
    
    int value = currentNode->data;
    
    if(head == currentNode)
    {
        head = nullptr;
    }
    
    tail = prevNode;
    
    delete currentNode;
    
    return value;
}

int LinkedList::front()
{
    if(isEmpty())
    {
        cout << "List is empty!!" << endl;
        return -1;
    }
    
    return head->data;
}

int LinkedList::back()
{
    if(isEmpty())
    {
        cout << "List is empty!!" << endl;
        return - 1;
    }
    
    return tail->data;
}

int LinkedList::getAt(int index)
{
    if(isEmpty())
    {
        cout << "List is empty!!" << endl;
        return - 1;
    }
    
    Node* currentNode = head;
    
    for(int i =0; i < index; ++i)
    {
        currentNode = currentNode->next;
        
        if(currentNode == nullptr)
        {
            cout << "List out of index : valueAt(" << index << ")" << endl;
            return -1;
        }
    }
    
    return currentNode->data;
}

void LinkedList::insert(int index, int value)
{
    Node* currentNode = head;
    Node* prevNode = nullptr;
    
    for(int i =0; i < index; ++i)
    {
        prevNode = currentNode;
        currentNode = currentNode->next;
        
        if(currentNode == nullptr)
        {
            cout << "List out of index : insert(" << index << ")" << endl;
            return;
        }
    }
    
    Node* newNode = new Node(value);
    
    if(prevNode  == nullptr)        // head에 추가
    {
        newNode->next = head;
        head = newNode;
        
        if(tail == nullptr)
            tail = newNode;
    }
    else{
        prevNode->next = newNode;
        newNode->next = currentNode;
    }
}

void LinkedList::erase(int index)
{
    Node* currentNode = head;
    Node* prevNode = nullptr;
    
    for(int i =0; currentNode &&  i < index; ++i)
    {
        prevNode = currentNode;
        currentNode = currentNode->next;
        
        if(currentNode == nullptr)
        {
            cout << "List out of index : earse(" << index << ")" << endl;
            return;
        }
    }
    
    if(prevNode == nullptr) // head 삭제
    {
        // list has only one item
        if(head == tail)
            tail = nullptr;
        
        head = head->next;
    }
    else{
        prevNode->next = currentNode->next;
        
        if(tail == currentNode)
            tail = prevNode;
    }
    
    delete currentNode;
}


// 1이면 가장 마지막 위치의 값 반환
int LinkedList::nFromBack(int n)
{
    if(n < 1 )
    {
        cout << "Minimum value is 1" << endl;
        return -1;
    }
    
    Node* currentNode = head;
    Node* nthNode = nullptr;
    
    for(int i =0; currentNode && i < n; ++i)
    {
        currentNode = currentNode->next;
    }
    
    if(currentNode == nullptr)
    {
        cout << "List out of index : nFromBack(" << n << ")" << endl;
        return -1;
    }

    nthNode = head;
    
    while (currentNode) {
        currentNode = currentNode->next;
        nthNode = nthNode->next;
    }
    
    return nthNode->data;
}

void LinkedList::reverse()
{
    Node* currentNode = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    
    tail = head;
    
    while (currentNode) {
        next = currentNode->next;
        
        currentNode->next = prev;
        
        prev = currentNode;
        currentNode = next;
    }
    
    head = prev;
}

void LinkedList::print()
{
    Node* current = head;
    
    printf("[HEAD : %p] [TAIL : %p]\n", head, tail);
    
    if(isEmpty())
    {
        cout << "Linked list is empty!" << endl;
        return;
    }
    
    
    while(current)
    {
        if(current == head)
            cout << " H";
        cout << current->data;
        if(current == tail)
            cout << "T ";
        
        cout << " ";
        current = current->next;
    }
    cout << endl;
}
