//
//  BinaryTree.cpp
//  Tree
//
//  Created by 김준영 on 2023/06/09.
//

#include "BinaryTree.hpp"
#include <string>
#include <iostream>
#include <queue>

using namespace std;

BinaryTree::BinaryTree(){
    root = nullptr;
}

void BinaryTree::insert(const Employee &employee){
    Node* newNode = new Node{employee, nullptr, nullptr};
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->data = employee;
    
    if(root == nullptr){
        root = newNode;
        return;
    }
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        Node* currentNode = q.front();
        q.pop();
        
        if(currentNode->left == nullptr){
            currentNode->left = newNode;
            return;
        }else if(currentNode->right == nullptr){
            currentNode->right = newNode;
            return;
        }else{
            q.push(currentNode->left);
            q.push(currentNode->right);
        }
    }
}

void BinaryTree::printPreorder(){
    printPreorder(root);
}
void BinaryTree::printPreorder(Node *node){
    if(node != nullptr){
        node->data.printInfo();
        printPreorder(node->left);
        printPreorder(node->right);
    }
}

void BinaryTree::printInorder(){
    printInorder(root);
}
void BinaryTree::printInorder(Node* node){
    if(node != nullptr){
        printInorder(node->left);
        node->data.printInfo();
        printInorder(node->right);
    }
}

void BinaryTree::printPostorder(){
    printPostorder(root);
}
void BinaryTree::printPostorder(Node* node){
    if(node != nullptr){
        printPostorder(node->left);
        printPostorder(node->right);
        node->data.printInfo();
    }
}
