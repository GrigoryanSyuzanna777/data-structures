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

int countOccurrencesOfValue(struct Node* node, int x) {
    if (node == nullptr)
        return 0;

    int count = 0;
    if (node -> data == x) 
        count = 1;

    return count + countOccurrencesOfValue(node->left, x) + countOccurrencesOfValue(node->right, x);
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(3);
    root->right->right = new Node(4);
    root->left->left->left = new Node(4);
    root->left->left->right = new Node(2);

    int x = 4;

    cout << "Number of occurances of number " << x << " is: " << countOccurrencesOfValue(root, x) << "\n";
    return 0;
}