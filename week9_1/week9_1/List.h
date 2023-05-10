#ifndef List_h
#define List_h
#include <iostream>
#include <sstream>

using namespace std;

template <class T>
class Node{
public:
    T data;
    Node<T>* prevlink;
    Node<T>* nextlink;
};

template <class T>
class HeadNode{
public:
    Node<T>* Lhead;
    Node<T>* Rhead;
};

template <class T>
class List{
public:
    HeadNode<T>* createList(){
        HeadNode<T>* H = new HeadNode<T>;
        H->Lhead = NULL;
        H->Rhead = NULL;
        return H;
    }
    
    bool SearchList(HeadNode<T>* H, T x){
        Node<T>* searchNode;
        searchNode = H->Rhead;
        bool result = false;
        
        if(H->Rhead->data == x){
            result = true;
        }else{
            while(searchNode->nextlink != NULL){
                searchNode = searchNode->nextlink;
                if(searchNode->data == x){
                    result = true;
                }
            }
        }
        
        return result;
    }
    
    void insertThisEnd(HeadNode<T>* H, T target, T x){
        if(SearchList(H, target) == false){
            cout << "존재하지 않는 역 입니다" << endl;
        }else{
            Node<T>* targetNode;
            Node<T>* NewNode = new Node<T>;
            NewNode->data = x;
            NewNode->nextlink = NULL;
            NewNode->prevlink = NULL;
            targetNode = H->Rhead;
            
            while(targetNode->nextlink != NULL){
                targetNode = targetNode->nextlink;
                if(targetNode->data == target){
                    break;
                }
            }
            
            NewNode->prevlink = targetNode;
            NewNode->nextlink = targetNode->nextlink;
            targetNode->nextlink->prevlink = NewNode;
            targetNode->nextlink = NewNode;
            
            if(NewNode->nextlink == NULL){
                H->Lhead = NewNode;
            }
        }
    }
    
    void insertEnd(HeadNode<T>* H, T x){
        Node<T>* prevNode;
        Node<T>* NewNode = new Node<T>;
        NewNode->data = x;
        NewNode->prevlink = NULL;
        NewNode->nextlink = NULL;
        
        if(H->Rhead == NULL){
            H->Rhead = NewNode;
            H->Lhead = NewNode;
        }
        else{
            prevNode = H->Lhead;
            prevNode->nextlink = NewNode;
            NewNode->prevlink = prevNode;
            H->Lhead = NewNode;
        }
    }
    
    void renameList(HeadNode<T>* H, T oriName, T reName){
        if(SearchList(H, oriName) == false){
            cout << oriName << "역은 존재하지 않는 역입니다.";
        }else{
            Node<T>* searchNode = H->Rhead;
            
            while(searchNode->nextlink != NULL){
                searchNode = searchNode->nextlink;
                if(searchNode->data == oriName){
                    searchNode->data = reName;
                    break;
                }
            }
        }
    }
    
    void insertThis(HeadNode<T>* H, T beforeData, T afterData, T x){
        if(SearchList(H, x) == true){
            cout << x << "역은 이미 존재하는 역입니다." << endl;
        }
        else if(SearchList(H, beforeData) == false){
            cout << beforeData << "역은 존재하지 않는 역입니다." << endl;
        }
        else if(SearchList(H, afterData) == false){
            cout << afterData << "역은 존재하지 않는 역입니다." << endl;
        }
        else{
            Node<T>* prevNode;
            Node<T>* nextNode;
            Node<T>* NewNode = new Node<T>;
            NewNode->data = x;
            NewNode->prevlink = NULL;
            NewNode->nextlink = NULL;
            
            prevNode = H->Rhead;
            nextNode = H->Rhead;
            
            while(prevNode->data != beforeData){
                prevNode = prevNode->nextlink;
            }
            while(nextNode->data != afterData){
                nextNode = nextNode->nextlink;
            }
            
            if(prevNode->nextlink == nextNode){
                NewNode->nextlink = prevNode->nextlink;
                NewNode->prevlink = prevNode;
                prevNode->nextlink = NewNode;
                NewNode->nextlink->prevlink = NewNode;
            }
            else{
                while(prevNode->nextlink != nextNode){
                    Node<T>* tmp = prevNode->nextlink;
                    prevNode->nextlink = tmp->nextlink;
                    if(prevNode->nextlink == nextNode) break;
                }
                NewNode->nextlink = prevNode->nextlink;
                NewNode->prevlink = prevNode;
                prevNode->nextlink = NewNode;
                NewNode->nextlink->prevlink = NewNode;
                
            }
        }
    }
    
    void deleteNode(HeadNode<T>* H, T delData) {
        if (SearchList(H, delData) == false) {
            cout << delData << "역은 존재하지 않는 역입니다." << endl;
        }
        else {
            Node<T>* delNode;
            delNode = H->Rhead;

            while (delNode->data != delData) {
                delNode = delNode->nextlink;
            }

            if (delNode != NULL) {
                if (delNode == H->Lhead) {
                    if (delNode == H->Rhead) {
                        H->Rhead = NULL;
                        H->Lhead = NULL;
                    }
                    else {
                        if (delNode->prevlink != NULL) {
                            delNode->prevlink->nextlink = NULL;
                            H->Lhead = delNode->prevlink;
                        }
                    }
                }
                else if (delNode == H->Rhead) {
                    if (delNode->nextlink != NULL) {
                        H->Rhead = delNode->nextlink;
                        delNode->nextlink->prevlink = NULL;
                    }
                }
                else {
                    if (delNode->prevlink != NULL && delNode->nextlink != NULL) {
                        delNode->prevlink->nextlink = delNode->nextlink;
                        delNode->nextlink->prevlink = delNode->prevlink;
                    }
                }
                delete delNode;
            }
            else {
                cout << "삭제할 노드가 없습니다." << endl;
            }
        }
    }

    
    void printList(HeadNode<T>* h){
        Node<T>* p;
        p = h->Rhead;
        
        while(p != NULL){
            cout << p->data;
            p = p->nextlink;
            if(p != NULL) cout << " - ";
        }
        cout << endl;
    }
   
};

#endif /* List_hpp */
