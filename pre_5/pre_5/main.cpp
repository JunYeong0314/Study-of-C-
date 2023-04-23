#include "Queue.hpp"
#include <iostream>

int main(){
    Queue<int> q = Queue<int>(5);
    
    for(int i=1; i<10; i++){
        q.Push(i);
    }
    for(int i=1; i<4; i++){
        q.Pop();
    }
    q.Push(32);
    q.Push(33);
    q.Push(34);
    for(int i=0; i<q.getCapacity(); i++){
        cout << q.queue[i] << " ";
    }
    cout << endl;
    q.Push(35);
    
    
    for(int i=0; i<q.getCapacity(); i++){
        cout << q.queue[i] << " ";
    }
    cout << endl;
}
