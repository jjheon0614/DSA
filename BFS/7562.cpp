#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int map[300][300];
bool visited[300][300];
int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[8] = {-2, 2, -1, 1, -2, 2, -1, 1};


void bfs(int x1, int y1, int x2, int y2, int length) {
    queue<pair<int, int>> q;
    q.push({x1, y1});
    map[x1][y1] = 0;
    visited[x1][y1] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= length || ny >= length) continue;
            if (visited[nx][ny]) continue;

            map[nx][ny] = map[x][y] + 1;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}


int main() {

    int T;
    cin >> T;
    vector<int> v;

    for (int i = 0; i < T; i++) {
        int length, x1, y1, x2, y2;
        cin >> length;
        cin >> x1 >> y1;
        cin >> x2 >> y2;

        if (x1 == x2 && y1 == y2) {
            v.push_back(0);
        } else {
            bfs(x1, y1, x2, y2, length);
            v.push_back(map[x2][y2]);
        }
        

        for (int j = 0; j < length; j++) {
            for (int k = 0; k < length; k++) {
                map[j][k] = 0;
                visited[j][k] = false;
            }
        }
    }


    for (int i = 0; i < T; i++) {
        cout << v[i] << "\n";
    }

    return 0;
}