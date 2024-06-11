#include <iostream>

using namespace std;

int board[2200][2200];
int cnt[2];

bool check(int x, int y, int n) {
    int val = board[x][y];
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (board[i][j] != val) {
                return false;
            }
        }
    }

    return true;
}

void func(int x, int y, int n) {

    if (check(x, y, n)) {
        cnt[board[x][y]] += 1;
        return;
    }

    int half = n / 2;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            func(x + i * half, y + j * half, half);
        }
    }
}

int main(void) {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    func(0, 0, n);

    for (int i = 0; i < 2; i++) {
        cout << cnt[i] << "\n";
    }

    return 0;
}