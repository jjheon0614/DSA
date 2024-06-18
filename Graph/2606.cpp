#include <iostream>
#include <queue>

using namespace std;

int n, m;
int cnt = 0;
vector<int> arr[101];
bool vis[101];

void bfs() {

    queue<int> q;
    q.push(1);
    vis[1] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < arr[cur].size(); i++) {
            if (vis[arr[cur][i]]) continue;

            q.push(arr[cur][i]);
            cnt++;
            vis[arr[cur][i]] = true;
        }
    }
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
    cout << cnt << "\n";

    return 0;
}