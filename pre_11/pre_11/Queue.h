//
//  Queue.h
//  pre_11
//
//  Created by 김준영 on 2023/04/24.
//

#ifndef Queue_h
#define Queue_h
#include <iostream>

using namespace std;

template <class T>
class Queue{
private:
    int rear, front, capacity;
public:
    T* queue;
    Queue(int queueCapacity=10);
    inline bool IsEmpty() const;
    inline T& Front() const;
    inline T& Rear() const;
    int getCapacity();
    void Push(const T& item);
    void Pop();
};

template <class T>
int Queue<T>::getCapacity(){
    return capacity;
}

template <class T>
Queue<T>::Queue(int queueCapacity):capacity(queueCapacity){
    queue = new T[capacity];
    rear = front = 0;
}

template <class T>
inline bool Queue<T>::IsEmpty() const{
    return rear == front;
}

template <class T>
inline T& Queue<T>::Front() const{
    if(IsEmpty()) throw "Queue is Empty";
    return (front+1)%capacity;
}

template <class T>
inline T& Queue<T>::Rear() const{
    if(IsEmpty()) throw "Queue is Empty";
    return (rear+1)%capacity;
}

template <class T>
void Queue<T>::Push(const T& item){
    if((rear+1)%capacity == front){
        T* newQueue = new T[capacity*2];
        int start = front;
        
        if(start < 2){
            copy(queue, queue+capacity, newQueue);
        }else{
            copy(queue+start+1, queue+capacity, newQueue);
            copy(queue, queue+front, newQueue+(capacity-front-1));
        }
        front = capacity*2-1;
        rear = capacity-2;
        capacity *= 2;
        delete[] queue;
        queue = newQueue;
    }
    rear = (rear+1)%capacity;
    queue[rear] = item;
}

template <class T>
void Queue<T>::Pop(){
    if(IsEmpty()){
        cout << "Queue is Empty" << endl;
        return;
    }
    cout << "Pop of value : " << queue[(front+1)%capacity] << endl;
    queue[(front+1)%capacity] = 0;
    front = (front+1) % capacity;
}
#endif /* Queue_h */
