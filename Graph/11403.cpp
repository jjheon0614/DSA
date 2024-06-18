#include <iostream>
#include <vector>

using namespace std;

vector<int> arr[101];
bool vis[101];
int result[101][101];
int n;

void dfs(int start, int cur) {
    vis[cur] = true;
    for (int i = 0; i < arr[cur].size(); i++) {
        if (arr[cur][i] == start) result[start][start] = 1;
        if (vis[arr[cur][i]]) continue;
        result[start][arr[cur][i]] = 1;
        dfs(start, arr[cur][i]);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            if (num == 1) {
                arr[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        dfs(i, i);
        fill(vis, vis + 101, false);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}