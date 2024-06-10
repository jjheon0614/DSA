#include <iostream>
#include <vector>
#include <queue>
#define MAX 51

using namespace std;

int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {

    int T;
    cin >> T;

    vector<int> v;

    for (int i = 0; i < T; i++) {
        int M, N, K;
        cin >> M >> N >> K;

        for (int j = 0; j < K; j++) {
            int x, y;
            cin >> x >> y;

            map[y][x] = 1;
        }

        queue<pair<int, int>> q;
        int count = 0;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (map[j][k] == 1 && !visited[j][k]) {
                    count++;
                    q.push({j, k});
                    visited[j][k] = true;

                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for (int l = 0; l < 4; l++) {
                            int nx = x + dx[l];
                            int ny = y + dy[l];

                            if (nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny] == 1) {
                                continue;
                            }
                            if (map[nx][ny] == 0) {
                                continue;
                            }

                            q.push({nx, ny});
                            visited[nx][ny] = 1;
                        }
                    }
                }
            }
        }

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                map[j][k] = 0;
                visited[j][k] = false;
            }
        }

        v.push_back(count);
    }

    for (int i = 0; i < T; i++) {
        cout << v[i] << "\n";
    }
    return 0;
}