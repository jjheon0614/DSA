#include <iostream>

using namespace std;

const int INF = 0x3f3f3f3f;
int n, m;
int arr[102][102];

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
    }

    for (int i = 1; i <= n; i++) {
        arr[i][i] = 0;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
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

    return 0;
}