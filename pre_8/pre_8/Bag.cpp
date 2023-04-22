#include "Bag.hpp"
#include <iostream>

Bag::Bag(int bagCapacity):capacity(bagCapacity),top(-1){
    array = new int[capacity];
}
Bag::~Bag(){}

Stack::~Stack(){
    delete[] array;
}
