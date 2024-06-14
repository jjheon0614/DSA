#include <iostream>

using namespace std;

int arr[10];
int n, m;

bool check() {
    for (int i = 0; i < m; i++) {
        for (int j = i; j < m ; j++) {
            if (arr[i] > arr[j]) {
                return false;
            }
        }
    }

    return true;
}

void func(int k) {

    if (k == m) {
        if (check()) {
            for (int i = 0; i < m; i++) {
                cout << arr[i] << " ";
            }
            cout << "\n";
            return;
        }
        return;
    }

    for (int i = 1; i <= n; i++) {
        arr[k] = i;
        func(k + 1);
    }
}


int main() {

    cin >> n >> m;
    func(0);

    return 0;
}