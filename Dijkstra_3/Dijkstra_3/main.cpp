#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Student {
    int num;
    string name;
    string major;

    Student(int num, string name, string major) : num(num), name(name), major(major) {}
    void printInfo() {
        cout << "ID: " << num << ", Name: " << name << ", Major: " << major << endl;
    }

};

struct Node {
    Student data;
    Node* left;
    Node* right;
};

class BST {
public:
    BST() : root(nullptr) {}

    void addStudent(Student s) {
        Node* newNode = new Node{s, nullptr, nullptr};

        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* p = root, * pp = nullptr;
        while (p) {
            pp = p;
            if (s.num < p->data.num)
                p = p->left;
            else if (s.num > p->data.num)
                p = p->right;
        }
        if (s.num < pp->data.num)
            pp->left = newNode;
        else if (s.num > pp->data.num)
            pp->right = newNode;
        else
            root = newNode;
    }

    void searchStudent(int num) {
        Node* p = root;

        while (p) {
            if (p->data.num > num)
                p = p->left;
            else if (p->data.num < num)
                p = p->right;
            else {
                p->data.printInfo();
                return;
            }
        }
        cout << "No search Student" << endl;
    }

    void printInorder() {
        printInorder(root);
    }
    void printInorder(Node* node) {
        if (node != nullptr) {
            printInorder(node->left);
            node->data.printInfo();
            printInorder(node->right);
        }
    }

    void deleteStudent(int num) {
        Node* delNode = root;
        Node* prevNode = nullptr;

        while (delNode) {
            if (delNode->data.num > num) {
                prevNode = delNode;
                delNode = delNode->left;
            }
            else if (delNode->data.num < num) {
                prevNode = delNode;
                delNode = delNode->right;
            }
            else {
                break;
            }
        }

        if (delNode == nullptr)
            return;  // 해당 노드가 존재하지 않으면 종료

        if (delNode->left == nullptr && delNode->right == nullptr) {
            if (prevNode == nullptr)
                root = nullptr;
            else if (prevNode->left == delNode)
                prevNode->left = nullptr;
            else
                prevNode->right = nullptr;
            delete delNode;
        }
        else if (delNode->right == nullptr) {
            if (prevNode == nullptr)
                root = delNode->left;
            else if (prevNode->left == delNode)
                prevNode->left = delNode->left;
            else
                prevNode->right = delNode->left;
            delete delNode;
        }
        else if (delNode->left == nullptr) {
            if (prevNode == nullptr)
                root = delNode->right;
            else if (prevNode->left == delNode)
                prevNode->left = delNode->right;
            else
                prevNode->right = delNode->right;
            delete delNode;
        }
        else {
            Node* p = delNode->right;
            Node* prevP = delNode;

            while (p->left) {
                prevP = p;
                p = p->left;
            }

            delNode->data = p->data;
            if (prevP->left == p)
                prevP->left = p->right;
            else
                prevP->right = p->right;
            delete p;
        }
    }

private:
    Node* root;
};

int main() {
    BST s;

    s.addStudent(Student(8, "Alice", "Com"));
    s.addStudent(Student(2, "Bob", "Com"));
    s.addStudent(Student(3, "Cindy", "Com"));
    s.addStudent(Student(4, "David", "Com"));
    s.addStudent(Student(12, "Eve", "Com"));
    s.addStudent(Student(11, "Fve", "Com"));
    s.addStudent(Student(9, "Gve", "Com"));
    s.addStudent(Student(15, "Hve", "Com"));
    s.addStudent(Student(13, "Ive", "Com"));
    s.addStudent(Student(18, "Jve", "Com"));
    s.addStudent(Student(16, "Kve", "Com"));
    s.addStudent(Student(19, "Lve", "Com"));

    s.deleteStudent(15);

    cout << "Inorder" << endl;
    s.printInorder();

    return 0;
}
