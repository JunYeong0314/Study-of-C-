//
//  main.cpp
//  Tree
//
//  Created by 김준영 on 2023/06/09.
//

#include <iostream>
#include "BinaryTree.hpp"
#include <string>

using namespace std;

int main() {
    BinaryTree tree;
    tree.insert(BinaryTree::Employee("Alice", "Manager"));
    tree.insert(BinaryTree::Employee("Bob", "Developer"));
    tree.insert(BinaryTree::Employee("Cindy", "Designer"));
    tree.insert(BinaryTree::Employee("David", "Developer"));
    tree.insert(BinaryTree::Employee("Eve", "HR"));
    tree.insert(BinaryTree::Employee("Jun", "Designer"));
    cout << "Preorder traversal:" << endl;
    tree.printPreorder();
    cout << endl;

    cout << "Inorder traversal:" << endl;
    tree.printInorder();
    cout << endl;

    cout << "Postorder traversal:" << endl;
    tree.printPostorder();
    cout << endl;


    return 0;
}
