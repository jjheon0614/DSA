#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            sum += arr[i];
        } else {
            arr[i] += arr[i - 1];
            sum += arr[i];
        }
    }

    cout << sum << "\n";

    return 0;
}

// 다른 풀이
// int main() {

//     cin >> n;
//     int arr[1001];
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     sort(arr, arr + n);
    
//     int total = 0;
//     int ans = 0;
//     for (int i = 0; i < n; i++) {
//         ans += arr[i] + total;
//         total += arr[i];
//     }

//     cout << ans << "\n";

//     return 0;
// }