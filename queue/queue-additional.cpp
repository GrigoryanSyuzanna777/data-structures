#include <iostream>
#include <queue>
using namespace std;

struct Pair {
    int first;
    char second;
};

int main() {
    queue<int> q1({ 1, 2, 3 });
    queue<char> q2({ 'c', 'b', 'a' });
    queue<Pair> q3;

    while (!q1.empty()) {
        q3.push({ q1.front(), q2.front() });
        q1.pop();
        q2.pop();
    }

    while (!q3.empty()) {
        cout << q3.front().first << " " << q3.front().second << "\n";
        q3.pop();
    }
    return 0;
}