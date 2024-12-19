#include <iostream>
#include <queue>
using namespace std;

template <typename T>
void print(queue<T> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    cout << "\n";
}

template<typename T>
queue<T> removeDuplicates(queue<T> q) {
    queue<T> result, temp;

    while (!q.empty()) {
        T current = q.front();
        q.pop();

        bool is_unique = true;
        while (!temp.empty()) {
            if (temp.front() == current) {
                is_unique = false;
                break;
            }
            temp.pop();
        }

        if (is_unique)
            result.push(current);

        temp = result;
    }
     
    return result;
}

int main() {
    queue<int> q1({1, 3, 4, 2, 3, 4, 1, 1, 5});
    queue<int> q2 = removeDuplicates(q1);

    print(q2);
    return 0;
}