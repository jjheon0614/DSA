#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long dp[101];

int main() {

    cin >> n;
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        for (int j = 3; j < i; j++) {
            dp[i] = max(dp[i], dp[i - j] * (j - 1));
        }
    }

    cout << dp[n] << "\n";

    return 0;
}