#ifndef Queue_hpp
#define Queue_hpp
#include <iostream>

using namespace std;

template <class T>
class Queue{
private:
    int rear, front, capacity;
public:
    T* queue;
    Queue(int queueCapacity = 10);
    ~Queue();
    inline bool IsEmpty() const;
    inline T& Front() const;
    inline T& Rear() const;
    int getCapacity();
    T* getQueue();
    void Push(const T& item);
    void Pop();
};

template <class T>
int Queue<T>::getCapacity(){
    return capacity;
}

template <class T>
Queue<T>::Queue(int queueCapacity):capacity(queueCapacity){
    if(capacity < 1) throw "Queue capacity must be > 0";
    queue = new T[capacity];
    front = rear = 0;
}
template <class T>
Queue<T>::~Queue(){}

template <class T>
inline bool Queue<T>::IsEmpty() const{
    return front == rear;
}

template <class T>
inline T& Queue<T>::Front() const{
    if(IsEmpty()) throw "Queue is Empty";
    return queue[(front+1)%capacity];
}

template <class T>
inline T& Queue<T>::Rear() const{
    if(IsEmpty()) throw "Queue is Empty";
    return queue[rear];
}

template <class T>
inline void Queue<T>::Push(const T& x){
    if((rear+1)%capacity == front){
        int start = front;
        T* newQueue = new T[capacity*2];
        if(start < 2){
            cout << "start < 2 : " << start << endl;
            copy(queue+start+1, queue+capacity, newQueue);
        }else{
            cout << "start > 2 : " << start << endl;
            cout << "capacity : " << capacity << endl;
            cout << "front : " << front << endl;
            cout << "rear : " << rear << endl;
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
    queue[rear] = x;
}

template <class T>
void Queue<T>::Pop(){
    if(IsEmpty()){
        cout << "Queue is Empty" << endl;
        return;
    }
    front = (front+1) % capacity;
    cout << queue[front] << endl;
    queue[front] = 0;
}
#endif /* Queue_hpp */
