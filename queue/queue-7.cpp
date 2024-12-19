#include <iostream>
#include <queue>
using namespace std;

void print(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    cout << "\n";
}

int main() {
    queue<int> q1({ 1, 2, 3, 4, 5 }), q2({ 10, 20, 30 }), q3;
    while (!q1.empty() || !q2.empty()) {
        if (!q1.empty()) {
            q3.push(q1.front());
            q1.pop();
        }

        if (!q2.empty()) {
            q3.push(q2.front());
            q2.pop();
        }
    }

    print(q3);
    return 0;
}