#include <iostream>
#include <queue>
using namespace std;

void radixSort(int* a, int n) {
    queue<int> q1[10], q2[10];
    for (int i = 0; i < n; ++i) {
        q1[a[i] % 10].push(a[i]);
    }

    for (int i = 0; i < 10; ++i) {
        while (!q1[i].empty()) {
            int value = q1[i].front();
            q1[i].pop();
            q2[value / 10 % 10].push(value);
        }
    }

    int k = 0;
    for (int i = 0; i < 10; ++i) {
        while (!q2[i].empty()) {
            a[k++] = q2[i].front();
            q2[i].pop();
        }
    }
    cout << k << "\n";
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