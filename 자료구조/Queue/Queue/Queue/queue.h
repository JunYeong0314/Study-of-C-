#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>

using namespace std;

template<class T>
void ChangeSize1D(T* a, const int oldSize, const int newSize) {
	if (newSize < 0) throw "New length must be >= 0";

	T* temp = new T[newSize];
	int number = min(oldSize, newSize);
	
	copy(a, a + number, temp);
	delete[] a;
	a = temp;

}
template <class T>
class Queue {

public:
	Queue(int queueCapacity = 10);
	bool IsEmpty() const;

	T& Rear() const;
	T& Front() const;
	void Push(const T& item);
	void Pop();

private:
	T* queue;
	int front, rear, capacity;
};

template <class T>
Queue<T>::Queue(int queueCapacity): capacity(queueCapacity) {
	if (capacity < 1) throw "Queue capacity must be > 0";
	queue = new T[capacity];
	front = rear = 0;

}

template <class T>
inline bool Queue<T>::IsEmpty() const{ return front == rear; }

template<class T>
inline T& Queue<T>::Front() const{
	if (IsEmpty()) throw "Queue is empty";
	return queue[(front + 1) % capacity];
}

template<class T>
inline T& Queue<T>::Rear() const{
	if (IsEmpty()) throw "Queue is empty";
	return queue[rear];
}

template<class T>
void Queue<T>::Push(const T& x) {
	if ((rear + 1) % capacity == front) {
		ChangeSize1D(queue, capacity, 2 * capacity);
		capacity *= 2;
	}
	rear = (rear + 1) % capacity;
	queue[rear] = x;
}

template<class T>
void Queue<T>::Pop() {
	if (IsEmpty()) throw "Queue is empty";
	front = (front + 1) % capacity;
	queue[front].~T();
}
#endif
