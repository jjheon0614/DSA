#include <iostream>
#include <algorithm>

using namespace std;

int n;

int main() {

    cin >> n;
    int arr[1001];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int total = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += arr[i] + total;
        total += arr[i];
    }

    cout << ans << "\n";

    return 0;
}