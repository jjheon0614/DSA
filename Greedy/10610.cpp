#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    string n;
    cin >> n;

    sort(n.begin(), n.end(), greater<char>());
    if (n[n.length() - 1] != '0') cout << -1 << "\n";
    else {
        int sum = 0;
        for (auto ch: n) {
            sum += ch - '0';
        }
        if (sum % 3 == 0){
            cout << n;
        } else {
            cout << -1;
        }
    }

    return 0;
}