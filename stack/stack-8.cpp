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

stack<int> removeDuplicates(stack<int> st) {
    stack<int> result, temp;

    while (!st.empty()) {
        int current = st.top();
        temp = result;
        st.pop();

        bool is_unique = true;
        while (!temp.empty()) {
            if (temp.top() == current) {
                is_unique = false; 
                break;
            }

            temp.pop();
        }
        if (is_unique) {
            result.push(current);
        }
    }

    return result;
}

int main() {
    stack<int> st({ 2, 1, 3, 2, 1, 4, 2 }), res;

    res = removeDuplicates(st);
    print(res);
    return 0;
}