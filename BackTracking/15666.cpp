#include <iostream>
#include <algorithm>

using namespace std;

int arr[10];
int num[10];
int n, m;

void func(int k , int st) {
    if (k == m) {
        for (int i = 0; i < m; i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    int tmp = -1;
    for (int i = st; i < n; i++) {
        if (num[i] != tmp) {
            arr[k] = num[i];
            tmp = arr[k];
            func(k + 1, i);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> num[i];
    sort(num, num + n);

    func(0, 0);

    return 0;
}