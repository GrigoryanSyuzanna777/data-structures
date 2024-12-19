#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <iomanip> 
using namespace std;

const double inf = 1e9;

struct Node {
    double data;
    struct Node *left, *right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

double findMinValue(Node* node) {
    if (node == nullptr)
        return inf; 

    double left_min = findMinValue(node->left);

    double right_min = findMinValue(node->right);

    return min(node->data, min(left_min, right_min));
}

int main() {
    struct Node* root = new Node(1.5);
    root->left = new Node(2);
    root->right = new Node(3.4);
    root->left->left = new Node(4);
    root->left->right = new Node(5.45);
    root->right->left = new Node(3);
    root->left->left->left = new Node(4);
    root->left->left->right = new Node(0);
    root->left->left->left->right = new Node(-8);

    cout << fixed << setprecision(2);
    cout << "Minimum value of binary tree is: " << findMinValue(root) << "\n";
    return 0;
}