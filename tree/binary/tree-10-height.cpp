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

int findHeight(Node* node) {
    if (node == nullptr)
        return -1;

    int left_height = findHeight(node->left);
    int right_height = findHeight(node->right);

    return 1 + max(left_height, right_height);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->left = new Node(-8);

     cout << "Height of the binary tree is: " << findHeight(root) << "\n";
    return 0;
}