//
//  Bag.hpp
//  pre_8
//
//  Created by 김준영 on 2023/04/22.
//

#ifndef Bag_hpp
#define Bag_hpp
#include <iostream>

using namespace std;

class Bag{
protected:
    int* array;
    int capacity, top;
public:
    Bag(int bagCapacity=10);
    virtual ~Bag();
    virtual int Size() const{
        return capacity;
    }
    virtual bool isEmpty() const{
        return top == -1;
    }
    virtual int* Element() const{
        return array;
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
    Stack(int stackCapacity = 10){
        Bag::top = -1;
        array = new int[stackCapacity];
    }
    virtual ~Stack();
    
    int top() const{
        return Bag::array[Bag::top];
    }
    void Pop(){
        if(isEmpty()) throw "Stack is Empty";
        cout << "value of pop" << Bag::array[Bag::top] << endl;
        Bag::top--;
    }
};
#endif /* Bag_hpp */
