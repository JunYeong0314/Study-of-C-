//
//  main.cpp
//  BinarySearchTree
//
//  Created by 김준영 on 2023/06/09.
//

#include <iostream>
#include "BST.hpp"

using namespace std;

int main() {
    BST bst;
    bst.addStudent(Student{2020001, "Alice", "Computer Science"});
    bst.addStudent(Student{2020002, "Bob", "Mathematics"});
    bst.addStudent(Student{2020003, "Charlie", "Physics"});
    bst.addStudent(Student{2020004, "Dave", "Chemistry"});
    bst.addStudent(Student{2020005, "Eve", "Biology"});
    
    bst.searchStudent(2020003);
    bst.searchStudent(2020006);
    
    cout << "중위순회로 출력" << endl;
    bst.printInorder();
    
    return 0;
}
