#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <iomanip> 
using namespace std;

int count = 0;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

void traverseInorder(struct Node* node) {
    if (node == nullptr)
        return;

    traverseInorder(node->left);

    ++count;

    traverseInorder(node->right);
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Number of nodes is: ";
    traverseInorder(root);
    cout << count << "\n";
    // 4 2 5 1 3 6
    return 0;
}