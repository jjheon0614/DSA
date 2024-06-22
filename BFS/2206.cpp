#include <iostream>
#include <queue>
#include <tuple>
#include <string>

using namespace std;

int board[1001][1001];
int dist[1001][1001][2];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m;


int bfs() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j][0] = dist[i][j][1] = -1;
        }
    }

    dist[0][0][0] = dist[0][0][1] = 1;
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});

    while (!q.empty()) {
        int x, y, broken;
        tie(x, y, broken) = q.front();
        if (x == n - 1 && y == m - 1) return dist[x][y][broken];
        q.pop();

        int nextdist = dist[x][y][broken] + 1;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (board[nx][ny] == 0 && dist[nx][ny][broken] == -1) {
                dist[nx][ny][broken] = nextdist;
                q.push({nx, ny, broken});
            }

            if (!broken && board[nx][ny] == 1 && dist[nx][ny][1] == -1) {
                dist[nx][ny][1] = nextdist;
                q.push({nx, ny, 1});
            }
        }
    }

    return -1;
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

    cout << bfs() << "\n";

    return 0;
}