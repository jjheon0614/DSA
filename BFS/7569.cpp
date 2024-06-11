#include <iostream>
#include <queue>

using namespace std;

int board[101][101][101];
bool visited[101][101][101];
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int main() {

    int M, N, H;
    cin >> M >> N >> H;

    queue<pair<int, pair<int, int>>> q;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> board[j][k][i];
                if (board[j][k][i] == 1) {
                    q.push({j, {k, i}});
                    visited[j][k][i] = true;
                }
            }
        }
    }

    int result = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second.first;
        int z = q.front().second.second;
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= H) continue;
            if (board[nx][ny][nz] == -1) continue;
            if (visited[nx][ny][nz]) continue;

            visited[nx][ny][nz] = true;
            board[nx][ny][nz] = board[x][y][z] + 1;
            q.push({nx, {ny, nz}});
            result = max(result, board[nx][ny][nz]);
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (board[j][k][i] == 0) {
                    cout << -1 << "\n";
                    return 0;
                }
            }
        }
    }
    
    if (result == 0) {
        cout << result << "\n";
    } else {
        cout << result - 1 << "\n"; 
    }


    return 0;
}