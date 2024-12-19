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

int findMinValueAndRemove(queue<int> &q) {
    int min_value = q.front();
    int size = q.size();

    for (int i = 0; i < size; ++i) {
        int curr = q.front();
        q.pop();
        q.push(curr);

        if (curr < min_value)
            min_value = curr;
    }

    bool removed = false;
    for (int i = 0; i < size; ++i) {
        int current = q.front();
        q.pop();

        if (!removed && current == min_value)
            removed = true;
        else
            q.push(current);
    }

    return min_value;
}

void sort(queue<int> &q) {
    queue<int> result;

    int size = q.size();
    for (int i = 0; i < size; ++i) {
        int min_value = findMinValueAndRemove(q);
        result.push(min_value);
    }

    q = result;
}

int main() {
    queue<int> q({ 4, 2, 5, 3, 1, 2, 5, 4 });

    sort(q);
    
    print(q);
    return 0;
}