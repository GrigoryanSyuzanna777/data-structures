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

void printPreorder(struct Node* node) {
    if (node == nullptr)
        return;

    cout << node->data << " ";

    printPreorder(node->left);

    printPreorder(node->right);
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Preorder traversal of binary tree is: \n";
    printPreorder(root);
    cout << "\n";
    // 1 2 4 5 3 6
    return 0;
}