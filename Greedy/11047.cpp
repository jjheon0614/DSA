#include <iostream>


using namespace std;

int arr[11];

int main() {
    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int ans = 0;

    for (int i = N - 1; i >= 0; i--) {
        ans += K / arr[i];
        K = K % arr[i];
    }

    cout << ans << "\n";

    return 0;
}