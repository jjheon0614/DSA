#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int level;
        cin >> level;
        v.push_back(level);
    }

    sort(v.begin(), v.end(), greater<int>());

    int gold = 0;

    for (int i = 1; i < n; i++) {
        gold += v[0] + v[i];
    }

    cout << gold << "\n";

    return 0;
}