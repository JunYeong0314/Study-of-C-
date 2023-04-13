#ifndef BAG_H
#define BAG_H
#include <iostream>

using namespace std;

class Bag{
public:
    Bag(int bagCapacity = 10);
    virtual int Size() const{
        if(IsEmpty()) throw "Empty";
        return capacity;
    }
    virtual ~Bag();
    virtual bool IsEmpty() const{
        return top == -1;
    }
    virtual int Element() const{
        if(IsEmpty()) throw "Bag is Empty";
        return arr[top];
    }
    virtual void Push(const int x){
        if(capacity == top - 1){
            capacity *= 2;
            int *tmp = new int[capacity];
            copy(arr, arr+top, tmp);
            delete[] arr;
            arr = tmp;
        }
        arr[++top] = x;
    }
    virtual void Pop(){
        if(IsEmpty()) throw "Bag is Empty";
        arr[top--] = 0;
    }
    
protected:
    int *arr;
    int capacity;
    int top = -1;
};

class Stack:public Bag{
public:
    Stack(int stackCapacity=10);
    ~Stack();

};
#endif /* Bag_h */
