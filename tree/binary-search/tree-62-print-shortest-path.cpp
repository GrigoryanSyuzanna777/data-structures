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

void findShortestPath(Node* node, vector<int>& current_path, vector<int>& shortest_path) {
    if (node == nullptr) 
        return;

    current_path.push_back(node->data);

    if (node->left == nullptr && node->right == nullptr)
        if (shortest_path.empty() || current_path.size() < shortest_path.size())
            shortest_path = current_path;

    findShortestPath(node->left, current_path, shortest_path);
    findShortestPath(node->right, current_path, shortest_path);

    current_path.pop_back();
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(9);
    root->left->right = new Node(5);
    root->right->left = new Node(-5);
    root->right->right = new Node(15);
    root->left->left->left = new Node(4);
    root->left->left->right = new Node(0);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(0);
    root->left->left->left->left = new Node(-8);

    vector<int> current_path;
    vector<int> shortest_path;

    findShortestPath(root, current_path, shortest_path);

    cout << "The shortest path is: ";
    for (int value : shortest_path)
        cout << value << " ";

    cout << "\n";
    return 0;
}