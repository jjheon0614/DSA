#include <iostream>

using namespace std;

const int INF = 0x3f3f3f3f;
int v, e;
int board[402][402];

int main() {
    cin >> v >> e;

    for (int i = 1; i <= v; i++) {
        fill(board[i], board[i] + v + 1, INF);
        board[i][i] = 0;
    }

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        board[a][b] = c;
    }

    for (int k = 1; k <= v; k++) {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                if (board[i][j] > board[i][k] + board[k][j]) {
                    board[i][j] = board[i][k] + board[k][j];
                }
            }
        }
    }

    int dist = INF;
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            if (i == j || board[i][j] == INF) continue;

            dist = min(dist, board[i][j] + board[j][i]);
        }
    }
    if (dist == INF) {
        dist = -1;
    }

    cout << dist << "\n";

    return 0;
}