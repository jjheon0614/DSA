#include <iostream>
#include <algorithm>

using namespace std;

int n;
pair<int, int> s[100005];

int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i].second >> s[i].first;
    }
    sort(s, s + n);

    int ans = 0;
    int t = 0;
    for (int i = 0; i < n; i++) {
        if ( t > s[i].second) continue;
        ans++;
        t = s[i].first;
    }

    cout << ans << "\n";

    return 0;
}