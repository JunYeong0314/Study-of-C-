#include "Bag.hpp"
#include <iostream>

using namespace std;

int main(){
    Bag *b = new Bag(5);
    Bag *s = new Stack(5);
    
    for(int i=0; i<10; i++){
        b->Push(i);
    }
    b->Pop();
    
    for(int i=0; i<10; i++){
        s->Push(i);
    }
    for(int i=0; i<5; i++){
        s->Pop();
    }
}
