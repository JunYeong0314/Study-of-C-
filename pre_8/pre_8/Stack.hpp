//
//  Stack.hpp
//  pre_8
//
//  Created by 김준영 on 2023/04/22.
//

#ifndef Stack_hpp
#define Stack_hpp
#include <iostream>

using namespace std;

template <class T>
class Stack{
public:
    Stack(int stackCapacity=10);
    bool IsEmpty() const;
    ~Stack();
    T& Top() const;
    void Push(const T& item);
    void Pop();
private:
    T* stack;
    int capacity, top;
};

template <class T>
Stack<T>::~Stack(){
    delete[] stack;
}

template <class T>
Stack<T>::Stack(int stackCapacity):capacity(stackCapacity){
    stack = new T[capacity];
    top = -1;
}

template <class T>
bool Stack<T>::IsEmpty() const{
    return top == -1;
}

template <class T>
T& Stack<T>::Top() const{
    if(IsEmpty()) throw "Stack is Empty";
    return stack[top];
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

template <class T>
void Stack<T>::Pop(){
    if(IsEmpty()){
        cout << "Stack is Empty";
        return;
    }
    cout << "Pop of value : " << stack[top] << endl;
    stack[top--].~T();
}

#endif /* Stack_hpp */
