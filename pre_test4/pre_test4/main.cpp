//
//  main.cpp
//  pre_test4
//
//  Created by 김준영 on 2023/06/17.
//

#include <iostream>
#include <string>

using namespace std;

struct Lecture{
    string name;
    int num;
    
    Lecture(string name, int num) : name(name), num(num){}
    void printInfo(){
        cout << "Lecture : " << name << "(" << num << ")" << endl;
    }
};

struct Node{
    Lecture data;
    Node *left;
    Node *right;
};

class LinkedList{
public:
    LinkedList(){
        head->left = nullptr;
        head->right = nullptr;
    }
    
    bool searchNode(int num){
        Node* p = head->right;
        
        if(p == nullptr){
            return false;
        }
        
        while(true){
            if(p->data.num == num){
                return true;
                break;
            }
            else if(p->data.num != num && p->right == nullptr){
                return false;
            }
            p = p->right;
        }
    }
    
    void addLecture(Lecture lec){
        Node *newNode = new Node{lec, nullptr, nullptr};
        
        if(head->right == nullptr){
            head->right = newNode;
            return;
        }
        
        Node *p = head->right;
        while(p->right){
            p = p->right;
        }
        p->right = newNode;
        newNode->left = p;
    }
    
    void addThisLecture(Lecture lec, int num){
        Node *newNode = new Node{lec, nullptr, nullptr};
        
        if(!searchNode(num)){
            cout << "Not found" << endl;
            return;
        }
        
        if(head->right == nullptr){
            return;
        }
        else{
            Node *prevNode = head->right;
            while(prevNode->data.num != num){
                prevNode = prevNode->right;
            }
            
            if(prevNode->right == nullptr){
                prevNode->right = newNode;
                newNode->left = prevNode;
            }
            else{
                Node *nextNode = prevNode->right;
                newNode->left = prevNode;
                newNode->right = nextNode;
                
                prevNode->right = newNode;
                nextNode->left = newNode;
            }
        }
    }
    void addBet(Lecture lec, int prevNum, int nextNum){
        Node *newNode = new Node{lec, nullptr, nullptr};
        
        if(!searchNode(prevNum) || !searchNode(nextNum)){
            cout << "Not found" << endl;
            return;
        }
        
        Node *prevNode = head->right;
        while(prevNode->data.num != prevNum){
            prevNode = prevNode->right;
        }
        
        if(prevNode->right->data.num == nextNum){
            Node *nextNode = prevNode->right;
            prevNode->right = newNode;
            nextNode->left = newNode;
            
            newNode->left = prevNode;
            newNode->right = nextNode;
        }
        else{
            Node *nextNode = prevNode;
            
            while(nextNode->data.num != nextNum){
                nextNode = nextNode->right;
            }
            
            prevNode->right = newNode;
            nextNode->left = newNode;
            
            newNode->left = prevNode;
            newNode->right = nextNode;
        }
    }
    
    void delLecture(int num){
        if(!searchNode(num)){
            cout << "Not found" << endl;
        }
        
        Node *delNode = head->right;
        
        while(delNode->data.num != num){
            delNode = delNode->right;
        }
        Node *prevNode = delNode->left;
        Node *nextNode = delNode->right;
        
        if(delNode == head->right){
            head->right = nullptr;
            delete delNode;
        }
        else if(delNode->right == nullptr){
            prevNode->right = nullptr;
            delete delNode;
        }else{
            prevNode->right = nextNode;
            nextNode->left = prevNode;
            delete delNode;
        }
    }
    
    void disPlay(){
        Node *p = head->right;
        
        while(p){
            p->data.printInfo();
            p = p->right;
        }
    }
    
private:
    Node *head;
};

int main() {
    LinkedList list;
    list.addLecture(Lecture("Data", 101));
    list.addLecture(Lecture("Algorithm", 102));
    list.addLecture(Lecture("Operating", 103));
    list.addLecture(Lecture("Computer", 104));
    list.addThisLecture(Lecture("ADS", 105), 104);
    list.delLecture(102);
    list.disPlay();
   
}
