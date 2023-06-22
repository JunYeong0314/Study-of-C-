//
//  main.cpp
//  pre_finnal
//
//  Created by 김준영 on 2023/06/22.
//

#include <iostream>
#include <string>

using namespace std;

struct Lecture{
    string name;
    int num;
    
    Lecture(string name, int num) : name(name), num(num) {}
    void printInfo(){
        cout << "Lecture : " << name << "(" << num << ")" << endl;
    }
};

struct Node{
    Lecture data;
    Node *link;
    Node *prev;
};

class List{
public:
    List() : head(nullptr), tail(nullptr) {}
    
    void addLecture(Lecture data){
        Node *newNode = new Node{data, nullptr, nullptr};
        
        if(head == nullptr){
            head = newNode;
            tail = newNode;
            newNode->link = newNode;
            return;
        }
        
        tail->link = newNode;
        newNode->prev = tail;
        newNode->link = head;
        
        tail = newNode;
    }
    
    void disPlay(){
        Node *p = head;
        
        do{
            p->data.printInfo();
            p = p->link;
        }while(p != head);
    }
    
    void deleteLecture(int num){
        Node *delNode = nullptr;
        Node *prevNode = head;
        
        while(delNode->data.num != num){\
            prevNode = delNode;
            delNode = delNode->link;
        }
        
        prevNode->link = delNode->link;
        free(delNode);
    }
    void reverse(){
    }
    
private:
    Node *head;
    Node *tail;
};

int main() {
    List myList;
    
    myList.addLecture(Lecture("A", 101));
    myList.addLecture(Lecture("B", 102));
    myList.addLecture(Lecture("C", 103));
    myList.addLecture(Lecture("D", 104));
    
    myList.disPlay();
}
