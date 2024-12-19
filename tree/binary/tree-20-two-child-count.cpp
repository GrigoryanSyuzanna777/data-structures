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

int countTwoChildrenNodes(Node* node) {
    if (node == nullptr)
        return 0;

    int count = 0;

    if (node->left != nullptr && node->right != nullptr)
        count = 1;

    return count + countTwoChildrenNodes(node->left) + countTwoChildrenNodes(node->right);
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(3);
    root->left->left->left = new Node(4);
    root->left->left->right = new Node(0);
    root->left->left->left->left = new Node(-8);

    cout << "Number of nodes with two children is: " << countTwoChildrenNodes(root) << "\n";
    return 0;
}