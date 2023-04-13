#include <iostream>
#include "Bag.h"

using namespace std;

Bag::Bag(int bagCapacity){
    capacity = bagCapacity;
    arr = new int[capacity];
}

Bag::~Bag(){}

Stack::Stack(int stackCapacity):Bag(stackCapacity){}
Stack::~Stack(){}

