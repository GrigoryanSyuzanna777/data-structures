#include <iostream>
#include <queue>
using namespace std;

int digitCount(int n) {
    int count = 0;
    while (n > 0) {
        ++count;
        n /= 10;
    }
    
    return count;
}

void radixSort(int* a, int n) {
    queue<int> q[10];
    int max_len = 1;
    int size[10];
    int degree = 10;

    for (int i = 0; i < n; ++i) {
        q[a[i] % 10].push(a[i]);

        int count = digitCount(a[i]);
        if (count > max_len)
            max_len = count; 
    }

    cout << "max length: " << max_len << "\n";

    for (int i = 1; i < max_len; ++i) {
        for (int j = 0; j < 10; ++j) {
            size[j] = q[j].size();
        }

        for (int j = 0; j < 10; ++j) {
            int m = size[j];
            while (m--) {
                int value = q[j].front();
                q[j].pop();
                q[value / degree % 10].push(value);
            }
        }

        degree *= 10;
    }

    int k = 0;
    for (int i = 0; i < 10; ++i) {
        while (!q[i].empty()) {
            a[k++] = q[i].front();
            q[i].pop();
        }
    }
}

int main() {
    int n;
    cin >> n;
    int* a = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    radixSort(a, n);
    
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
    cout << "\n";

    delete []a;
    return 0;
}