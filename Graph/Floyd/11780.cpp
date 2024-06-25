#include <iostream>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;
int n, m;
int arr[102][102];
int nxt[102][102];

int main() {

    cin >> n;

    for (int i = 1; i <= n; i++) {
        fill(arr[i], arr[i] + 1 + n, INF);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;

        arr[a][b] = min(arr[a][b] , cost);
        nxt[a][b] = b;
    }

    for (int i = 1; i <= n; i++) {
        arr[i][i] = 0;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][k] + arr[k][j] < arr[i][j]) {
                    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == INF) cout << "0 ";
            else cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == 0 || arr[i][j] == INF){
                cout << "0\n";
                continue;
            }
            vector<int> path;
            int st = i;
            while (st != j) {
                path.push_back(st);
                st = nxt[st][j];
            }
            path.push_back(j);
            cout << path.size() << " ";
            for (auto x : path) cout << x << " ";
            cout << "\n";
        }
    }

    return 0;
}