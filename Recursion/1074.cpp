#include <iostream>
#include <cmath>

using namespace std;


int func(int n, int r, int c) {
    if (n == 0) return 0;

    int half = 1 << (n - 1);
    if (r < half && c < half) return func(n - 1, r, c);
    if (r < half && c >= half) return half * half + func(n - 1, r, c - half);
    if (r >= half && c < half) return 2 * half * half + func(n - 1, r - half, c);
    return 3 * half * half + func(n - 1, r - half, c - half);
}

int main() {
    int N, r, c;
    cin >> N >> r >> c;
    int count = 0;
    cout << func(N, r, c);

    return 0;
}