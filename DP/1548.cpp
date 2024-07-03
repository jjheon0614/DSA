#include <iostream>
#include <vector>

using namespace std;

int n;
int dp[1500002];

int main() {
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int t, p;
        cin >> t >> p;

        v.push_back({t, p});
    }


    int currentMax = 0;
    for (int i = 1; i <= n; i++) {
        currentMax = max(currentMax, dp[i]);
        if (i + v[i].first > n + 1) continue;
        dp[i + v[i].first] = max(dp[i + v[i].first], currentMax + v[i].second);
    }

    cout << currentMax << "\n";


    // dp[1] = 0;
    // dp[1 + v[0].first] = dp[1] + v[0].second;
    // int answer = 0;

    // for (int i = 2; i <= n; i++) {
    //     dp[i + v[i].first] = dp[i] + v[i].second;
    // }

    // cout << dp[n - 1] << "\n";


    return 0;
}