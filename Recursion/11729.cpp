#include <iostream>
#include <cmath>

using namespace std;

int result = 0;

void hanoi(int n, int start, int end) {
    if (n == 1) {
        cout << start << " " << end << "\n";
        return;
    }

    hanoi(n - 1, start, 6 - start - end);
    cout << start << " " << end << "\n";
    hanoi(n - 1, 6 - start - end, end);
}

int main() {

    int N;
    cin >> N;
    result = pow(2, N) - 1;
    cout << result << "\n";
    hanoi(N, 1, 3);

    return 0;
}