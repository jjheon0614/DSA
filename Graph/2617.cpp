#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj1[100];
vector<int> adj2[100];
int n, m;
int cnt = 0;

void bfs1(int st) {
    queue<int> q;
    q.push(st);
    bool visit[100];
    fill(visit, visit + 100, false);
    visit[st] = true;

    int num = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto nxt: adj1[cur]) {
            if (visit[nxt]) continue;

            q.push(nxt);
            num++;
            visit[nxt] = true;
        }
    }

    if (num >= (n + 1) / 2) cnt++;
}

void bfs2(int st) {
    queue<int> q;
    q.push(st);
    bool visit2[100];
    fill(visit2, visit2 + 100, false);
    visit2[st] = true;

    int num = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto nxt: adj2[cur]) {
            if (visit2[nxt]) continue;

            q.push(nxt);
            num++;
            visit2[nxt] = true;
        }
    }

    if (num >= (n + 1) / 2) cnt++;
}

int main() {

    cin >> n >> m;
    int u, v;
    for (int i = 0 ; i < m; i++) {
        cin >> u >> v;
        adj1[u].push_back(v);
        adj2[v].push_back(u);
    }


    for (int i = 1; i <= n; i++) {
        bfs1(i);
        bfs2(i);
    }

    
    cout << cnt << "\n";

    return 0;
}