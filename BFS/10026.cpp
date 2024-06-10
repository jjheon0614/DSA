#include <iostream>
#include <queue>

using namespace std;
char map1[100][100];
char map2[100][100];
bool visited1[100][100];
bool visited2[100][100];
int N;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int i, int j, char c) {
    queue<pair<int, int>> q;
    q.push({i, j});
    visited1[i][j] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited1[nx][ny]) continue;
            if (map1[nx][ny] != c) continue;

            q.push({nx, ny});
            visited1[nx][ny] = true;
        }
    }

}


void bfs2(int i, int j, char c) {
    queue<pair<int, int>> q;
    q.push({i, j});
    visited2[i][j] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited2[nx][ny]) continue;
            if (map2[nx][ny] != c) continue;

            q.push({nx, ny});
            visited2[nx][ny] = true;
        }
    }

}


int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++) {
            map1[i][j] = str[j];
            if (str[j] == 'G') {
                map2[i][j] = 'R';
            } else {
                map2[i][j] = str[j];
            }
        }
    }

    string color = "RGB";
    int normal = 0;
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map1[i][j] == color[k] && !visited1[i][j]) {
                    normal++;
                    bfs(i, j, color[k]);
                }

            }
        }
    }

    string color2 = "RB";
    int rg = 0;
    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map2[i][j] == color2[k] && !visited2[i][j]) {
                    rg++;
                    bfs2(i, j, color2[k]);
                }

            }
        }
    }

    cout << normal << " " << rg << "\n";
    

    return 0;
}