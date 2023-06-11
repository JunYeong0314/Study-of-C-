//
//  BinaryTree.hpp
//  Tree
//
//  Created by 김준영 on 2023/06/09.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp
#include <iostream>
#include <string>

using namespace std;

class BinaryTree{
public:
    struct Employee{
        string name;
        string position;
        
        Employee(const string& name, const string& position) : name(name), position(position){}
        
        void printInfo(){
            cout << "Name : " << name << ", Position : " << position << endl;
        }
    };
    
    struct Node{
        Employee data;
        Node* left;
        Node* right;
    };
    
    BinaryTree();
    void insert(const Employee& employee);
    void printPreorder();
    void printPreorder(Node* node);
    void printInorder();
    void printInorder(Node* node);
    void printPostorder();
    void printPostorder(Node* node);
    
private:
    Node* root;

};

#endif /* BinaryTree_hpp */
