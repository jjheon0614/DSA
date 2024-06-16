#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int n;
    cin >> n;

    int arrA[n];
    int arrB[n];

    for (int i = 0; i < n; i++) {
        cin >> arrA[i];
    }

    sort(arrA, arrA + n);

    for (int i = 0; i < n; i++) {
        cin >> arrB[i];
    }

    sort(arrB, arrB + n);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans += arrA[i] * arrB[n - i - 1];
    }

    cout << ans << "\n";

    return 0;
}