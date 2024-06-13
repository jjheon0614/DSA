#include <iostream>

using namespace std;

int n, m;
int arr[10];
bool isused[10];

bool check() {
    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
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
            for (int i = 0; i < m ; i++) {
                cout << arr[i] << " ";
            }
            cout << "\n";
            return;
        }
        return;
    }

    for (int i = 1; i <= n; i++) {
        if(!isused[i]) {
            arr[k] = i;
            isused[i] = true;
            func(k + 1);
            isused[i] = false;
        }
    }
}

int main() {

    cin >> n >> m;
    func(0);

    return 0;
}