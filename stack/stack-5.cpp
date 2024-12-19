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

int main() {
    stack<int> st1, st2, st3;

    st1.push(1);
    st1.push(2);
    st1.push(3);

    st2.push(10);
    st2.push(20);
    st2.push(30);

    while (!st1.empty())
    {
        st2.push(st1.top());
        st1.pop();
    }

    while (!st2.empty())
    {
        st3.push(st2.top());
        st2.pop();
    }

    print(st3);
    return 0;
}