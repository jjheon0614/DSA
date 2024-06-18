#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int cnt = 0;
vector<int> arr[501];
bool vis[501];
int dist[501];

void bfs() {
    queue<int> q;
    q.push(1);
    vis[1] = true;
    dist[1] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < arr[cur].size(); i++) {
            if (vis[arr[cur][i]]) continue;

            q.push(arr[cur][i]);
            vis[arr[cur][i]] = 1;
            dist[arr[cur][i]] = dist[cur] + 1;
            if (dist[arr[cur][i]] > 0 && dist[arr[cur][i]] <= 2) {
                cnt++;
            }
        }
    }

    cout << cnt << "\n";
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    bfs();

    return 0;
}