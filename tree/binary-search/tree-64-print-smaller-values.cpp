#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <iomanip> 
using namespace std;

const double inf = 1e9;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

void printSmallerThan(Node* root, int value) {
    if (root == nullptr)
        return;  

    if (root->data < value)
        cout << root->data << " ";  

    if (root->left != nullptr)
        printSmallerThan(root->left, value);  

    if (root->data < value && root->right != nullptr)
        printSmallerThan(root->right, value);  
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

    int value = 4;

    cout << "All values that are less than " << value << "\n";
    printSmallerThan(root, value);
    cout << "\n";

    return 0;
}