#include <iostream>
#include "stack.h"

using namespace std;

int main() {
	Stack<int> s(10);

	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	cout << s.Top() << endl;

	s.Pop();
	s.Pop();
	cout << s.Top() << endl;

	return 0;
}