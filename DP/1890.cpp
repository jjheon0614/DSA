#include <iostream>

using namespace std;

int n;
long long board[102][102];
long long dp[102][102];

int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    dp[0][0] = 0;
    dp[board[0][0]][0] = 1;
    dp[0][board[0][0]] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;
            if (dp[i][j] == 0 || i == n - 1 && j == n - 1) {
                continue;
            }

            dp[i + board[i][j]][j] += dp[i][j];
            dp[i][j + board[i][j]] += dp[i][j];
        }
    }

    cout << dp[n - 1][n - 1] << "\n";

    return 0;
}