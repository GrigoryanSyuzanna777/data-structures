#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <iomanip> 
using namespace std;

struct Node {
    int data; 
    Node* left;
    Node* right;
    Node (int value) {
        data = value;
        left = right = nullptr;
    }
};

void printInorderRecursive(struct Node* node) {
    if (node == nullptr) return;

    printInorderRecursive(node->left);

    cout << node->data << " ";

    printInorderRecursive(node->right);
}

void printInorderIterative(struct Node* root) {
    if (root == NULL) return;

    stack<Node*> st;
    Node* current = root;

    while (!st.empty() || current != NULL) {
        while (current != NULL) {
            st.push(current);
            current = current->left;
        }

        current = st.top();
        st.pop();
        cout << current->data << " ";

        current = current->right;
    }
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Inorder traversal of binary tree is: \n";
    printInorderRecursive(root);
    cout << "\n";
    // 4 2 5 1 3 6

    printInorderIterative(root);
    cout << "\n";
    // 4 2 5 1 3 6
    return 0;
}