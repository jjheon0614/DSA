#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> arr[1001];
int vis[1001];

void dfs(int cur) {
    vis[cur] = true;

    for (int i = 0; i < arr[cur].size(); i++) {
        if (!vis[arr[cur][i]]) {
            dfs(arr[cur][i]);
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
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            count++;
            dfs(i);
        }
    }

    cout << count << "\n";

    return 0;
}