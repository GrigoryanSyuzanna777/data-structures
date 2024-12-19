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

void printPreorderRecursive(struct Node* node) {
    if (node == nullptr)
        return;

    cout << node->data << " ";

    printPreorderRecursive(node->left);

    printPreorderRecursive(node->right);
}

void printPreorderIterative(struct Node* root) {
    if (root == nullptr) return;

    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* current = s.top();
        s.pop();

        cout << current->data << " ";

        if (current->right != nullptr)
            s.push(current->right);

        if (current->left != nullptr)
            s.push(current->left);
    }
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Preorder traversal of binary tree is: \n";
    printPreorderRecursive(root);
    cout << "\n";
    // 1 2 4 5 3 6

    printPreorderIterative(root);
    cout << "\n";
    // 1 2 4 5 3 6
    return 0;
}