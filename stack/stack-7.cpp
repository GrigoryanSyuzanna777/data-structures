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
    stack<int> st1, st1_reversed, st2, st2_reversed;

    st1.push(1);
    st1.push(2);
    st1.push(3);

    st2.push(100);
    st2.push(200);
    st2.push(300);
    st2.push(400);
    st2.push(500);

    while (!st1.empty()) {
        st1_reversed.push(st1.top());
        st1.pop();
    }
    while (!st2.empty()) {
        st2_reversed.push(st2.top());
        st2.pop();
    }

    while (!st1_reversed.empty() || !st2_reversed.empty()) {
        if (!st1_reversed.empty()) {
            cout << st1_reversed.top() << " ";
            st1_reversed.pop();
        }
        
        if (!st2_reversed.empty()) {
            cout << st2_reversed.top() << " ";
            st2_reversed.pop();
        }
    }

    cout << "\n";
    return 0;
}