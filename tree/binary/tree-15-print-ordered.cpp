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

void printOrdered(struct Node* node) {
    if (node == nullptr)
        return;

    queue<Node*> q;
    q.push(node);

    while (!q.empty()) {
        Node* current = q.front();
        cout << current->data << " ";
        q.pop();

        if (current->left != nullptr) 
            q.push(current->left);
        if (current->right != nullptr) 
            q.push(current->right);
    }            
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->left->left = new Node(-8);
    root->left->left->right = new Node(-5);
    root->left->right->right = new Node(0);

    cout << "Ordered traversal of binary tree is: \n";
    printOrdered(root);
    cout << "\n";

    return 0;
}