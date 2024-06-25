#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
int n, m, K;
int board[202][202];
int person[1001];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        fill(board[i], board[i] + 1 + n, INF);
        board[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;

        board[a][b] = t;
    }

    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> person[i];
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (board[i][j] > board[i][k] + board[k][j]) {
                    board[i][j] = board[i][k] + board[k][j];
                }
            }
        }
    }

    vector<pair<int, int>> dist;
    int mn = 0x3f3f3f3f;

    for (int i = 1; i <= n; i++) {
        int mx = 0;
        for (int k = 0; k < K; k++) {
            mx = max(mx, board[person[k]][i] + board[i][person[k]]);
        }
        mn = min(mn, mx);
        dist.push_back({i, mx});
    }

    for (int i = 0; i < dist.size(); i++) {
        if (mn == dist[i].second) {
            cout << dist[i].first << " ";
        }
    }

    return 0;
}