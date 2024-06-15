#include <iostream>

using namespace std;

int n;
int arr[14];
bool isused[14];
int num[14];

void func(int k) {
    if (k == 6) {
        for (int i = 0; i < 6; i++) {
            cout << num[arr[i] - 1] << " ";
        }
        cout << "\n";
        return;
    }

    int st = 1;
    if (k != 0) st = arr[k - 1];

    for (int i = st; i <= n; i++) {
        if (!isused[i]) {
            arr[k] = i;
            isused[i] = true;
            func(k + 1);
            isused[i] = false;
        }
    }
}

int main() {

    while (1) {
        cin >> n;
        if (n == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }

        func(0);
        cout << "\n";
    }

    return 0;
}