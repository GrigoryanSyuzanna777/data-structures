#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <iomanip> 
#include <algorithm>
using namespace std;

const double inf = 1e9;
vector<int> result;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

void inorderTraversal(struct Node* node) {
    if (node == nullptr)
        return;

    inorderTraversal(node->left);

    result.push_back(node->data);

    inorderTraversal(node->right);
}

void printNonDecreasing(Node* root) {
    inorderTraversal(root);

    sort(result.begin(), result.end());
    for (int it : result) 
        cout << it << " ";

    cout << "\n";
    return;
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

    cout << "Tree values in non decreasing order\n";
    printNonDecreasing(root);

    return 0;
}