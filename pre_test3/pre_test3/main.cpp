//
//  main.cpp
//  pre_test3
//
//  Created by 김준영 on 2023/06/15.
//

#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>

using namespace std;

struct Student{
    int id;
    string name;
    string major;
    
    Student(int id, string name, string major) : id(id), name(name), major(major) {}
    void printInfo(){
        cout << "ID: " << id << ", Name: " << name << ", Major: " << major << endl;
    }
};

struct Node{
    Student data;
    Node *left;
    Node *right;
};

class BST{
public:
    BST() : root{nullptr} {}
    
    void addStudent(Student s){
        Node *newNode = new Node{s, nullptr, nullptr};
        
        if(root == nullptr){
            root = newNode;
            return;
        }
        
        Node *p=root, *pp = 0;
        while(p){
            pp = p;
            if(p->data.id > s.id) p = p->left;
            else if(p->data.id < s.id) p = p->right;
        }
        if(pp->data.id > s.id) pp->left = newNode;
        else if(pp->data.id < s.id) pp->right = newNode;
        else root = newNode;
    }
    
    void searchStudent(int id){
        Node *p = root;
        
        while(p){
            if(p->data.id > id) p = p->left;
            else if(p->data.id < id) p = p->right;
            else{
                cout << "Search Succes !" << endl;
                p->data.printInfo();
                return;
            }
        }
        cout << "No Student found with ID : " << id << endl;
    }
    
    void printInorder(){
        printInorder(root);
    }
    void printInorder(Node *node){
        if(node != nullptr){
            printInorder(node->left);
            node->data.printInfo();
            printInorder(node->right);
        }
    }
    
    void deleteStudent(int id){
        Node *delNode = root;
        Node *prevNode = nullptr;
        
        while(delNode){
            if(delNode->data.id > id){
                prevNode = delNode;
                delNode = delNode->left;
            }
            else if(delNode->data.id < id){
                prevNode = delNode;
                delNode = delNode->right;
            }else{
                break;
            }
        }
        
        if(delNode == nullptr){
            cout << id << " not found !" << endl;
            return;
        }
        if(delNode->left == nullptr && delNode->right == nullptr){
            if(prevNode == nullptr) root = nullptr;
            else if(prevNode->left == delNode) prevNode->left = nullptr;
            else prevNode->right = nullptr;
            delete delNode;
        }
        else if(delNode->right == nullptr){
            if(prevNode == nullptr) root = delNode->left;
            else if(prevNode->left == delNode) prevNode->left = delNode->left;
            else prevNode->right = delNode->left;
            delete delNode;
        }
        else if(delNode->left == nullptr){
            if(prevNode == nullptr) root = delNode->right;
            else if(prevNode->left == delNode) prevNode->left = delNode->right;
            else prevNode->right = delNode->right;
            delete delNode;
        }
        else{
            Node *p = delNode->right;
            Node *prevP = delNode;
            
            while(p->left){
                prevP = p;
                p = p->left;
            }
            
            delNode->data = p->data;
            if(prevP->left == p){
                prevP->left = p->right;
            }
            else{
                prevP->right = p->right;
            }
            delete p;
        }
    }
private:
    Node *root;
};
int main() {
    BST bst;
    bst.addStudent(Student{2020001, "Alice", "Computer Science"});
    bst.addStudent(Student{2020002, "Bob", "Mathematics"});
    bst.addStudent(Student{2020003, "Charlie", "Physics"});
    bst.addStudent(Student{2020004, "Dave", "Chemistry"});
    bst.addStudent(Student{2020005, "Eve", "Biology"});
    
    bst.searchStudent(2020003);
    bst.searchStudent(213);
    
    cout << "중위순회 출력" << endl;
    bst.printInorder();
    
    bst.deleteStudent(2020001);
    cout << "삭제 후 출력" << endl;
    bst.printInorder();

}
