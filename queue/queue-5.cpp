#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void print(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    cout << "\n";
}

// Reverse with recursion
void reverseQueue(queue<int> &q) {
    if (q.empty())
        return;

    int front = q.front();
    q.pop();
    reverseQueue(q);
    q.push(front);
}

// Reverse with stack
void reverseQueueWithStack(queue<int> &q) {
    stack<int> st;

    while (!q.empty()) {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }
}

int main() {
    queue<int> q1({1, 2, 3, 4}), q2({ 10, 20, 30, 40, 50 }), q3;

    while (!q1.empty()) {
        q3.push(q1.front());
        q1.pop();
    }

    reverseQueue(q2);
    // reverseQueueWithStack(q2);

    while (!q2.empty()) {
        q3.push(q2.front());
        q2.pop();
    }

    print(q3);
    return 0;
}