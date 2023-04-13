#include <iostream>
#include "Bag.h"

using namespace std;

int main(){
    Bag b(3);
    Stack s(3);
    
    b.Push(1);
    b.Push(2);
    b.Push(3);
    
    cout << b.Element() << endl;
    
    s.Push(1);
    s.Push(2);
    
    cout << s.Element() << endl;
}
