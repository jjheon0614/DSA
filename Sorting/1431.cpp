#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n;

int calculateSum(string str) {
    int result = 0;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            result += str[i] - '0';
        }
    }

    return result;
}

bool calculateAlpha(string a, string b) {
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }

    return true;
}

bool cmp(pair<int, string> a, pair<int, string> b) {
    if (a.first != b.first) {
        return a.first < b.first;
    } else {
        if (calculateSum(a.second) != calculateSum(b.second)) {
            return calculateSum(a.second) < calculateSum(b.second);
        } else {
            return calculateAlpha(a.second, b.second);
        }
    }
}

int main() {

    cin >> n;

    vector<pair<int, string>> serial;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        int size = str.length();
        serial.push_back(make_pair(size, str));
    }

    sort(serial.begin(), serial.end(), cmp);

    for (int i = 0; i < n; i++) {
        cout << serial[i].second << "\n";
    }

    return 0;
}