#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int arr[25][25];
bool vis[25][25];
int cnt = 0;
int n;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
vector<int> v;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;
    
    int num = 1;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (vis[nx][ny] || arr[nx][ny] != 1) continue;

            q.push({nx, ny});
            vis[nx][ny] = true;
            num++;
        }
    }
    v.push_back(num);
}


int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++) {
            arr[i][j] = str[j] - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 1 && !vis[i][j]) {
                cnt++;
                bfs(i, j);
            }
        }
    }

    sort(v.begin(), v.end());

    cout << cnt << "\n";
    for (int i = 0; i < cnt; i++) {
        cout << v[i] << "\n";
    }

    return 0;
}