#include <iostream>

using namespace std;

int n;
int s[301], w[301];
int result = 0;

void func(int num, int count) {
    if (num == n) {
        return;
    }

    if (s[num] <= 0) {
        func(num + 1, count);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (num == i || s[i] <= 0) continue;

        s[i] -= w[num];
        s[num] -= w[i];
        if (s[i] <= 0) {
            count++;
        }
        if (s[num] <= 0) {
            count++;
        }
        if (result < count) {
            result = count;
        }
        func(num + 1, count);
        if (s[i] <= 0) {
            count--;
        }
        if (s[num] <= 0) {
            count--;
        }
        s[i] += w[num];
        s[num] += w[i];
    }
}

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s[i] >> w[i];
    }

    func(0, 0);

    cout << result << "\n";

    return 0;
}