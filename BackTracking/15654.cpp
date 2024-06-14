#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[10];
bool isused[10];
vector<int> v;


void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << v[arr[i] - 1] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!isused[i]) {
            arr[k] = i;
            isused[i] = true;
            func(k + 1);
            isused[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());
    func(0);

    return 0;
}