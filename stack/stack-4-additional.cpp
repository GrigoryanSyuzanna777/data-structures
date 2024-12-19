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
    stack<int> st1, st1_reversed;
    stack<char> st2, st2_reversed;
    stack<double> st3, st3_reversed;

    st1.push(1);
    st1.push(2);

    st2.push('a');
    st2.push('b');

    st3.push(1.5);
    st3.push(2.5);
    st3.push(3.5);
    st3.push(4.5);

    int n1 = st1.size(), n2 = st2.size(), n3 = st3.size();

    while (!st1.empty()) {
        st1_reversed.push(st1.top());
        st1.pop();
    }
    while (!st2.empty()) {
        st2_reversed.push(st2.top());
        st2.pop();
    }
    while (!st3.empty()) {
        st3_reversed.push(st3.top());
        st3.pop();
    }

    int i = 0;
    while (i < n1 + n2 + n3) {
        int empty_count = 0;
        if (!st1_reversed.empty()) {
            cout << st1_reversed.top() << " ";
            st1_reversed.pop();
        }
        
        if (!st2_reversed.empty()) {
            cout << st2_reversed.top() << " ";
            st2_reversed.pop();
        }

        if (!st3_reversed.empty()) {
            cout << st3_reversed.top() << " ";
            st3_reversed.pop();
        }
        empty_count = st1_reversed.empty() + st2_reversed.empty() + st3_reversed.empty();

        if (empty_count >= 2)
            break;
        ++i;
    }

    cout << "\n";
    return 0;
}