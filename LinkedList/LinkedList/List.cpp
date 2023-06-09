#include "List.hpp"
#include <iostream>

using namespace std;

List::List() {head = nullptr;}

List::Lecture* List::searchLecture(int number){
    Lecture* p;
    p = head;
    
    while(p != nullptr && p->number != number){
        p = p->next;
    }
    
    if(p == nullptr){
        cout << "Lecture not found" << endl;
    }
    return p;
}

void List::addLecture(string name, int number){
    Lecture* newNode = new Lecture(name, number);
    newNode->next = nullptr;
    newNode->prev = nullptr;
    
    if(head == nullptr){
        head = newNode;
        return;
    }
    
    Lecture* LastNode = head;
    while(LastNode->next != NULL){
        LastNode = LastNode->next;
    }
    newNode->prev = LastNode;
    LastNode->next = newNode;
}

void List::deleteLecture(int number){
    Lecture* delNode = searchLecture(number);
    if(delNode == nullptr){
        cout << "Found Error" << endl;
        return;
    }
    Lecture* prevNode = delNode->prev;
    Lecture* nextNode = delNode->next;
    
    if(prevNode != nullptr) prevNode->next = nextNode;
    if(nextNode != nullptr) nextNode->prev = prevNode;
    if(delNode == head) head = nextNode;
    
    free(delNode);
    cout << "Successfully delete Lecture" << endl;
}

void List::displayLecture(){
    Lecture* p;
    p = head;
    
    if(p == nullptr){
        return;
    }
    
    while(p != nullptr){
        cout << "Lecture: " << p->name << "(" << p->number << ")" << endl;
        p = p->next;
    }
    cout << endl;
}

void List::reverse(){
    if(head == nullptr) return;
    
    Lecture* prev = nullptr;
    Lecture* current = head;
    Lecture* next = nullptr;
    
    while(current != nullptr){
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }
    head = prev;
}
