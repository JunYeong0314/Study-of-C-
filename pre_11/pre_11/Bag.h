#ifndef Bag_h
#define Bag_h
#include <iostream>

using namespace std;

class Bag{
protected:
    int* array;
    int capacity, top;
public:
    Bag(int bagcapacity=10):capacity(bagcapacity){
        top = -1;
        array = new int[capacity];
    }
    virtual int Size() const{
        return capacity;
    }
    virtual bool IsEmpty() const{
        return top == -1;
    }
    virtual void Push(const int x){
        if(top == capacity-1){
            capacity *= 2;
            int* tmp = new int[capacity];
            copy(array, array+top, tmp);
            delete[] array;
            array = tmp;
        }
        array[++top] = x;
    }
    virtual void Pop(){
        cout << "delete array" << endl;
        delete[] array;
    }
};

class Stack:public Bag{
public:
    Stack(int stackCapacity){
        Bag::capacity = stackCapacity;
        Bag::top = -1;
        Bag::array = new int[Bag::capacity];
    }
    int top() const{
        return Bag::array[Bag::top];
    }
    void Pop(){
        cout << "Pop of value : " << Bag::array[Bag::top] << endl;
        Bag::top--;
    }
};

#endif /* Bag_h */
