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

void printInorder(struct Node* node) {
    if (node == nullptr)
        return;

    printInorder(node->left);

    cout << node->data << " ";

    printInorder(node->right);
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Inorder traversal of binary tree is: \n";
    printInorder(root);
    cout << "\n";
    // 4 2 5 1 3 6
    return 0;
}