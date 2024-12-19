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

bool isPalindrome(stack<char> st) {
    stack<char> st_straight = st, st_reversed;

    while (!st.empty()) {
        st_reversed.push(st.top());
        st.pop();
    }

    while (!st_straight.empty()) {
        if (st_straight.top() != st_reversed.top()) 
            return false;
        st_straight.pop();
        st_reversed.pop();
    }

    return true;
}

int main() {
    stack<char> st;

    st.push('a');
    st.push('b');
    st.push('c');
    st.push('b');
    st.push('a');

    cout << (isPalindrome(st) ? "yes" : "no") << "\n";
    return 0;
}