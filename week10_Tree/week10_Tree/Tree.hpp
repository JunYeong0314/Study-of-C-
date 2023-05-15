#ifndef Tree_hpp
#define Tree_hpp
#include <iostream>

using namespace std;

template <class T> class Tree;

template <class T>
class TreeNode{
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode(T data, TreeNode<T>* left, TreeNode* right){
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

template <class T>
class Tree{
public:
    void preorder(TreeNode<T>* node){
        if(node != NULL){
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    } // VLR(전위순회)
    void inorder(TreeNode<T>* node){
        if(node != NULL){
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    } // LVR(중위순회)
    void postorder(TreeNode<T>* node){
        if(node != NULL){
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    } // LRV(후위순회)
    
    void removeNode(TreeNode<T>* node);
    
};


#endif /* Tree_hpp */
