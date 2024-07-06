#include <iostream>
#include <vector>


using namespace std;

int n, s, m;
vector<int> v;
bool dp[52][1010];

int main() {

    cin >> n >> s >> m;
    v.push_back(0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    dp[0][0] = s;
    dp[0][1] = s;

    if (s - v[1] >= 0) dp[1][s - v[1]] = true;
    if (s + v[1] <= m) dp[1][s + v[1]] = true; 

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (dp[i - 1][j] == true) {
                if (j - v[i] >= 0) dp[i][j - v[i]] = true;
                if (j + v[i] <= m) dp[i][j + v[i]] = true;
            }
        }
    }

    for (int i = m; i >= 0; i--) {
        if (dp[n][i] == true) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";

    return 0;
}