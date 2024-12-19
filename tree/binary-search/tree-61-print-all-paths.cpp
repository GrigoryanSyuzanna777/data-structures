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

void findPaths(Node* node, vector<int>& path) {
    if (node == nullptr)
        return;

    path.push_back(node->data);

    if (node->left == nullptr && node->right == nullptr) {
        cout << "The longest path from root to leaf ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << "\n";
    }
    else {
        findPaths(node->left, path);
        findPaths(node->right, path);
    }

    path.pop_back();
}

void printAllPaths(Node* root) {
    vector<int> path;
    findPaths(root, path);
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(4);
    root->left->left->right = new Node(0);
    root->left->left->left->left = new Node(-8);

    printAllPaths(root);
    return 0;
}