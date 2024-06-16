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