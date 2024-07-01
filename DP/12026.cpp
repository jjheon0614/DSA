#include <iostream>

using namespace std;

char street[1001];
int dp[1001];
int n;

void solution() {
	dp[1] = 0;
	for (int i = 1; i < n; i++) {
		if (street[i] == 'B') {
			for (int j = i + 1; j <= n; j++) {
				if (street[j] == 'O')
					dp[j] = min(dp[j], (j - i)*(j - i) + dp[i]);
			}
		}
		else if (street[i] == 'O') {
			for (int j = i + 1; j <= n; j++) {
				if (street[j] == 'J')
					dp[j] = min(dp[j], (j - i)*(j - i) + dp[i]);
			}
		}
		else {
			for (int j = i + 1; j <= n; j++) {
				if (street[j] == 'B')
					dp[j] = min(dp[j], (j - i)*(j - i) + dp[i]);
			}
		}
	}
	if (dp[n] == 9999999)
		cout << -1 << '\n';
	else
		cout << dp[n] << '\n';
}

int main() {

    cin >> n;

    for (int i = 1; i <= n; i++) {
		cin >> street[i];
	}

	fill(dp, dp + 1001, 9999999);
	solution();

    return 0;
}