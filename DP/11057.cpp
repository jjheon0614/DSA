#include <iostream>

using namespace std;

int n;
int dp[1001][1001];

int main () {

    cin >> n;

    for (int i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }

    
    for (int i = 9; i >= 0; i--) {
        dp[2][i] = 10 - i;
    }

    for (int i = 3; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            dp[i][j] = 0;
            for (int k = j; k <= 9; k++) {
                dp[i][j] += dp[i - 1][k] % 10007;
            } 
        }
    }

    int result = 0;
    for (int i = 0; i < 10; i++) {
        result += dp[n][i];
        result = result % 10007;
    }

    cout << result << "\n";

    return 0;
}