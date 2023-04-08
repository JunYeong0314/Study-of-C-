#include <iostream>
#include "queue.h"

using namespace std;

int main() {
	Queue<int> q(10);

	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	cout << "front: " << q.Front() << endl;
	cout << "rear: "<< q.Rear() << endl;

	q.Pop();
	q.Pop();
	cout << q.Front() << endl;
	cout << q.Rear() << endl;
}