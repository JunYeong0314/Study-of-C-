#ifndef CList_hpp
#define CList_hpp
#include <iostream>

using namespace std;

template <class T>
class Node{
public:
    int data;
    Node<T>* link;
    
    Node(int d = 0, Node<T>* n = NULL):data(d), link(n){}
};

template <class T>
class HeadNode{
public:
    Node<T>* head;
    HeadNode():head(NULL){}
};

template <class T>
class CList{
public:
    HeadNode<T>* createList(){
        return new HeadNode<T>;
    }
    void addNode(HeadNode<T>* H, T x){
        Node<T>* NewNode = new Node<T>(x);
        NewNode->link = NULL;
        
        if(H->head == NULL){
            H->head = NewNode;
            return;
        }
        
        Node<T>* LastNode = H->head;
        while(LastNode->link != NULL) LastNode = LastNode->link;
        LastNode->link = NewNode;
    }
    void printList(HeadNode<T>* h){
        Node<T>* p;
        p = h->head;
        
        while(p != NULL){
            cout << p->data;
            p = p->link;
            if(p != NULL) cout << " ";
        }
        cout << endl;
    }
    HeadNode<T>* reverse(HeadNode<T>* head){
        if(head == NULL) return NULL;
        
        Node<T>* prev = NULL;
        Node<T>* current = head->head;
        Node<T>* next = NULL;
        
        while(current != NULL){
            next = current->link;
            current->link = prev;
            prev = current;
            current = next;
        }
        head->head = prev;
        return head;
    }
};

#endif /* CList_hpp */
