#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<int> arr[52];
bool vis[52];
int score[52];
int n;

void bfs(int start) {
    queue<int> q;
    int dist[52];
    dist[start] = 0;
    q.push(start);
    vis[start] = true;

    int highest = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto nxt: arr[cur]) {
            if (vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = true;
            dist[nxt] = dist[cur] + 1;
            highest = max(highest, dist[nxt]);
        }
    }

    score[start] = highest;
}

int main() {

    cin >> n;
    while (1) {
        int u, v;
        cin >> u >> v;
        if (u == -1 && v == -1) {
            break;
        }

        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        bfs(i);
        fill(vis, vis + n + 1, false);
    }

    int lowest = score[1];

    map<int, vector<int>> m;
    for (int i = 1; i <= n; i++) {
        if (lowest > score[i]) {
            lowest = score[i];
        }
        m[score[i]].push_back(i);
    }

    cout << lowest << " " << m[lowest].size() << "\n";
    for (int i = 0; i < m[lowest].size(); i++) {
        cout << m[lowest][i] << " ";
    }

    return 0;
}