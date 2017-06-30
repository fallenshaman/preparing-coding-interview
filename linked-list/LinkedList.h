#pragma once

class LinkedList
{
public:
    struct Node
    {
        Node* next;
        int data;
        
        Node(int value) : next(nullptr), data(value) {}
    };

private:
    Node* head;
    Node* tail;
    
public:
    LinkedList():head(nullptr), tail(nullptr) {}
    ~LinkedList();
    
    int size();                 // 리스트 안의 데이터 수 반환
    bool isEmpty();             // 리스트가 비어있는지 반환
    void clear();               // 리스트의 모든 데이터 삭제
    
    void pushFront(int value);  // 리스트 앞에 데이터 추가
    int popFront();             // 리스트 앞에서 데이터 추출 및 제거
    
    void pushBack(int value);   // 리스트 뒤에 데이터 추가
    int popBack();              // 리스틑 뒤에서 데이터 추출 및 제거
    
    int front();                // 리스트 앞의 데이터 반환
    int back();                 // 리스트 뒤의 데이터 반환
    
    int getAt(int index);     // 인덱스 위치의 데이터 반환
    
    void insert(int index, int value);  // 인덱스 위치에 새로운 데이터 추가
    void erase(int index);      // 인덱스 위치의 데이터 제거
    
    void print();               // 리스트 내용 출력
    
    // 응용
    int nFromBack(int n);      // 뒤에서 n 번째 데이터 반환
    void reverse();             // 리스트 뒤집기
    

};
