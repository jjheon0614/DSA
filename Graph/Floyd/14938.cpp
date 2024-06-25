#include <iostream>

using namespace std;

const int INF = 0x3f3f3f3f;
int n, m, r;
int arr[102];
int board[102][102];

int main() {

    cin >> n >> m >> r;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        fill (board[i], board[i] + n + 1, INF);
    }

    for (int i = 0; i < r; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        board[a][b] = l;
        board[b][a] = l;
    }

    for (int i = 1; i <= n; i++) board[i][i] = 0;

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
            }
        }
    }
    
    int answer = 0;
    int total = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i][j] <= m) {
                total += arr[j];
            }
        }
        answer = max(answer, total);
        total = 0;

    }

    cout << answer << "\n";

    return 0;
}