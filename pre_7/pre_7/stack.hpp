//
//  stack.hpp
//  pre_7
//
//  Created by 김준영 on 2023/04/20.
//

#ifndef stack_hpp
#define stack_hpp
#include <iostream>

using namespace std;

template <class T>
class Stack{
public:
    Stack(int capacityStack = 10);
    bool IsEmpty();
    T& Top() const;
    void Pop();
    void Push(const T& x);
private:
    T* stack;
    int top;
    int capacity;
};

template <class T>
Stack<T>::Stack(int capacityStack):capacity(capacityStack){
    stack = new T[capacity];
    top = -1;
}

template <class T>
bool Stack<T>::IsEmpty(){
    return top == -1;
}

template <class T>
T& Stack<T>::Top() const{
    if(IsEmpty()) throw "Stack is Empty";
    return stack[top];
}

template <class T>
void Stack<T>::Pop(){
    if(IsEmpty()) throw "Stack is Empty";
    stack[top--].~T();
}

template <class T>
void Stack<T>::Push(const T& x){
    if(top == capacity-1){
        capacity *= 2;
        T* tmp = new T[capacity];
        copy(stack, stack+top, tmp);
        delete[] stack;
        stack = tmp;
    }
    stack[++top] = x;
}
#endif /* stack_hpp */
