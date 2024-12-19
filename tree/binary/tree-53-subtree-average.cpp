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

pair<double, int> calculateSubtreeAverage(Node* root) {
    if (!root)
        return { 0.0, 0 };  

    pair<double, int> left = calculateSubtreeAverage(root->left);
    pair<double, int> right = calculateSubtreeAverage(root->right);

    double sum = left.first + right.first + root->data;
    int count = left.second + right.second + 1;

    cout << "Node with value " << root->data << " has subtree average of: " << sum / count << endl;

    return { sum, count };
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

    calculateSubtreeAverage(root);

    return 0;
}