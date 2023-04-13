#include <iostream>
#include "Queue.h"

using namespace std;

int main(){
    Queue<int> q = Queue<int>(5);
    for(int i=0; i<5; i++){
        q.Push(i);
    }
    for(int i=0; i<3; i++){
        q.Pop();
    }
    for(int i=1; i<4; i++){
        q.Push(i);
    }
    
    cout << "Front : " << q.Front() << endl;
    cout << "Rear : " << q.Rear() << endl;
    return 0;
}
