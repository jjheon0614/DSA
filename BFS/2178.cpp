#include <iostream>
#include <queue>
#include <string>

using namespace std;

int board[101][101];
bool vis[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m;

void bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0][0] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] || board[nx][ny] == 0) continue;

            q.push({nx, ny});
            vis[nx][ny] = true;
            board[nx][ny] = board[x][y] + 1;
        }
    }
}


int main() {

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++) {
            board[i][j] = str[j] - '0';
        }
    }

    bfs();

    cout << board[n - 1][m - 1] << "\n";

    return 0;
}