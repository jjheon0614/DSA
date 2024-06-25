#include <iostream>

using namespace std;

const int INF = 0x3f3f3f3f;
int n, m;
int board[252][252];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        fill(board[i] + 1, board[i] + n + 1, INF);
        board[i][i] = 0;
    }

    
    for (int i = 0; i < m; i++) {
        int u, v, b;
        cin >> u >> v >> b;

        board[u][v] = 0;
        board[v][u] = !b;
    }

    for(int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
            }
        }
    }

    cin >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        cout << board[u][v] << '\n';
    }

    return 0;
}