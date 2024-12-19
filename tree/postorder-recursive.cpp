#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <iomanip> 
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

void printPostorderRecursive(struct Node* node) {
    if (node == nullptr)
        return;

    printPostorderRecursive(node->left);

    printPostorderRecursive(node->right);
    
    cout << node->data << " ";
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Postorder traversal of binary tree is: \n";
    printPostorderRecursive(root);
    cout << "\n";
    // 4 5 2 6 3 1
    return 0;
}