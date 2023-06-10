//
//  BST.hpp
//  BinarySearchTree
//
//  Created by 김준영 on 2023/06/09.
//

#ifndef BST_hpp
#define BST_hpp
#include <iostream>
#include <string>

using namespace std;

struct Student{
    int id;
    string name;
    string major;
};

struct Node{
    Student data;
    Node* left;
    Node* right;
};

class BST{
private:
    Node* root;
public:
    BST();
    void addStudent(Student data);
    void searchStudent(int id);
    void inorder(Node* root);
    void printInorder();
    
};

#endif /* BST_hpp */
