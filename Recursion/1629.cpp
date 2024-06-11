#include <iostream>

using namespace std;

long long POW(long long a, long long b, long long m) {
    if (b == 1) return a % m;
    long long val = POW(a, b / 2, m);
    val = val * val % m;
    if (b % 2 == 0) return val;
    return val * a % m;
}

int main() {

    long long A, B, C;
    cin >> A >> B >> C;
    cout << POW(A, B, C) << "\n";

    return 0;
}