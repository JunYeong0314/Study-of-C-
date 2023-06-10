//
//  BST.cpp
//  BinarySearchTree
//
//  Created by 김준영 on 2023/06/09.
//

#include "BST.hpp"
#include <string>
#include <iostream>

using namespace std;

BST::BST(){
    root = nullptr;
}

void BST::addStudent(Student data){
    Node* newNode = new Node{data, nullptr, nullptr};
    
    if(root == nullptr){
        root = newNode;
        return;
    }
    
    Node *p = root, *pp = 0;
    while(p){
        pp = p;
        if(data.id < p->data.id) p = p->left;
        else if(data.id > p->data.id) p = p->right;
        else{
            p->data.id = data.id;
            p->data.name = data.name;
            p->data.major = data.major;
            return;
        }
    }
    if(data.id < pp->data.id) pp->left = newNode;
    else if(data.id > pp->data.id) pp->right = newNode;
    else root = newNode;
}

void BST::searchStudent(int id){
    Node* p = root;
    
    if(root == nullptr){
        return;
    }
    
    while(p){
        if(id < p->data.id) p = p->left;
        else if(id > p->data.id) p = p->right;
        else{
            cout << "ID: " << p->data.id << " Name: " << p->data.name << " Major: " << p->data.major << endl;
            return;
        }
    }
    cout << "No student found with ID: " << id << endl;
}

void BST::inorder(Node *root){
    if(root == nullptr){
        return;
    }
    if(root != nullptr){
        inorder(root->left);
        cout << "ID: " << root->data.id << " Name: " << root->data.name << " Major: " << root->data.major << endl;
        inorder(root->right);
    }
}

void BST::printInorder(){
    inorder(root);
}


