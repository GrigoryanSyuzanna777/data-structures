#include <iostream>
#include <stack>
using namespace std;

struct Pair {
    int first;
    char second;
};

int main() {
    stack<int> s1({ 1, 2, 3 });
    stack<char> s2({ 'c', 'b', 'a' });
    stack<Pair> s3, temp;

    while (!s1.empty()) {
        s3.push({ s1.top(), s2.top() });
        s1.pop();
        s2.pop();
    }

    while (!temp.empty()) {
        s3.push(temp.top());
        temp.pop();
    }

    while (!s3.empty()) {
        cout << s3.top().first << " " << s3.top().second << "\n";
        s3.pop();
    }
    return 0;
}