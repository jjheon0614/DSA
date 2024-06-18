#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, t;
vector<int> pt[52];
vector<int> adj[52];
bool tr[52];

void bfs() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (tr[i]) q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int nxt: adj[cur]) {
            if (tr[nxt]) continue;
            tr[nxt] = 1;
            q.push(nxt);
        }
    }
}

int main() {

    cin >> n >> m >> t;
    while (t--) {
        int x;
        cin >> x;
        tr[x] = 1;
    }

    for (int i = 0; i < m; i++) {
        int no;
        cin >> no;

        int prv, nxt;
        cin >> prv;
        pt[i].push_back(prv);

        while (--no) {
            cin >> nxt;
            pt[i].push_back(nxt);
            adj[nxt].push_back(prv);
            adj[prv].push_back(nxt);
            swap(prv, nxt);
        }
    }

    bfs();

    int cnt = 0;
    for (int i = 0; i < m; i++) {
        bool known = 0;
        for (int p : pt[i]) if (tr[p]) known = 1;
        if (!known) cnt++;
    }

    cout << cnt << "\n";

    return 0;
}