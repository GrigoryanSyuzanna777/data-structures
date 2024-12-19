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

int sumUpToLevel(Node* node, int level) {
    if (!node) return 0; 

    int sum = 0;
    queue<pair<Node*, int>> q;  
    q.push({ node, 0 }); 

    while (!q.empty()) {
        pair<Node*, int> node = q.front();
        q.pop();

        Node* current_node = node.first;
        int current_level = node.second;

        if (current_level <= level) 
            sum += current_node->data;
       
        if (current_node->left) 
            q.push({ current_node->left, current_level + 1 });
      
        if (current_node->right)
            q.push({ current_node->right, current_level + 1 });
    }

    return sum;
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

    int level = 2;

    cout << "The sum of elements up to level " << level << " is: " << sumUpToLevel(root, level) << "\n";
    return 0;
}