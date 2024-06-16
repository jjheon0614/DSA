#include <iostream>
#include <string>

using namespace std;

int tmp, ans;
int sign = 1;

int main() {

    string str;
    cin >> str;

    for (char c : str) {
        if (c == '+' || c == '-') {
            ans += tmp * sign;
            if (c == '-') {
                sign = -1;
            }
            tmp = 0;
        } else {
            tmp *= 10;
            tmp += c - '0';
        }
    }

    ans += tmp * sign;
    cout << ans << "\n";

    return 0;
}