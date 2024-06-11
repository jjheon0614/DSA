#include <iostream>
#include <string>

using namespace std;

int board[65][65];
string res = "";

bool check(int x, int y, int n) {
    for(int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (board[x][y] != board[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void func(int x, int y, int n) {
    if (check(x, y, n)) {
        res += board[x][y];
        return;
    }

    int half = n / 2;
    res += "(";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            func(x + i * half, y + j * half, half);
        }
    }
    res += ")";
}

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++) {
            board[i][j] = str[j];
        }
    }

    func(0, 0, n);

    cout << res << "\n";

    return 0;
}