#include <iostream>
#include <stack>
using namespace std;

void print(stack<int> st) {
    stack<int> temp;

    while (!st.empty()) {
        temp.push(st.top());
        st.pop();
    }

    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }

    cout << "\n";
}

void sort(stack<int> &st) {
    stack<int> temp;

    while (!st.empty()) {
        int current = st.top();
        st.pop();

        while (!temp.empty() && temp.top() > current) {
            st.push(temp.top());
            temp.pop();
        }

        temp.push(current);
    }

    st = temp;
}

int main() {
    stack<int> st1, st2;

    st1.push(6);
    st1.push(2);
    st1.push(4);
    st1.push(1);
    st1.push(6);
    st1.push(10);
    st1.push(2);

    sort(st1);
    print(st1);

    return 0;
}