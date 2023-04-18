//
//  Queue.hpp
//  week7_1
//
//  Created by 김준영 on 2023/04/18.
//

#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

using namespace std;

template <class T>

class Queue{
public:
    Queue(int queueCapacity = 10);
    ~Queue();
    inline bool IsEmpty() const;
    inline T& Front() const;
    inline T& Rear() const;
    void Push(const T& item);
    void Pop();
    void createPassword();
private:
    T* queue;
    int rear;
    int front;
    int capacity;
};

template <class T>
Queue<T>::Queue(int queueCapacity):capacity(queueCapacity){
    if(capacity < 1) throw "Queue capacity must be >= 0";
    queue = new T[capacity];
    front = rear = 0;
}

template <class T>
Queue<T>::~Queue(){}

template <class T>
inline bool Queue<T>::IsEmpty() const{
    return rear == front;
}

template <class T>
inline T& Queue<T>::Front() const{
    if(IsEmpty()) throw "Queue is Empty";
    return queue[(front+1)%capacity];
}

template <class T>
inline void Queue<T>::Pop(){
    if(IsEmpty()){
        cout << "Queue is Empty" << endl;
        return;
    }
    front = (front+1) % capacity;
}

template <class T>
void Queue<T>::createPassword(){
    if(IsEmpty()){
        cout << "Queue is Empty" << endl;
        return;
    }
    front = (front+1) % capacity;
    cout << queue[front] << " ";
}


template <class T>
inline void Queue<T>::Push(const T& x){
    if((rear+1)%capacity == front){
        int start = front;
        T* newQueue = new T[capacity*2];
        if(start < 2){
            copy(queue+start, queue+rear, newQueue);
        }else{
            copy(queue+start, queue+rear, newQueue);
            copy(queue, queue+front-1, newQueue);
        }
        front = capacity*2-1;
        rear = capacity-2;
        capacity *= 2;
        delete[] queue;
        queue = newQueue;
    }
    rear = (rear+1)%capacity;
    queue[rear] = x;
}
template <class T>
inline T& Queue<T>::Rear() const{
    if(IsEmpty()) throw "Queue is Empty";
    return queue[rear];
}
#endif /* Queue_hpp */
