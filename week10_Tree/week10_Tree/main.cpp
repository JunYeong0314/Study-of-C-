//
//  main.cpp
//  week10_Tree
//
//  Created by 김준영 on 2023/05/15.
//

#include <iostream>
#include "Tree.hpp"

int main(){
    TreeNode<int>* n800 = new TreeNode<int>(800, NULL, NULL);
    TreeNode<int>* n400 = new TreeNode<int>(400, n800, NULL);
    TreeNode<int>* n500 = new TreeNode<int>(500, NULL, NULL);
    TreeNode<int>* n200 = new TreeNode<int>(200, n400, n500);
    TreeNode<int>* n600 = new TreeNode<int>(600, NULL, NULL);
    TreeNode<int>* n700 = new TreeNode<int>(700, NULL, NULL);
    TreeNode<int>* n300 = new TreeNode<int>(300, n600, n700);
    TreeNode<int>* n100 = new TreeNode<int>(100, n200, n300);
    
    Tree<int> t;
    
    cout << "전위순회 : ";
    t.preorder(n100);
    cout << endl;
    cout << "중위순회 : ";
    t.inorder(n100);
    cout << endl;
    cout << "후위순회 : ";
    t.postorder(n100);
    
    
}
