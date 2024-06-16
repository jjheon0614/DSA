#include <iostream>
#include <vector>


using namespace std;


int main() {

    int n;
    cin >> n;

    vector<pair<int, int>> flower;

    for (int i = 0; i < n; i++) {
        int startm, startd, endm, endd;
        cin >> startm >> startd >> endm >> endd;

        flower.push_back({startm * 100 + startd, endm * 100 + endd});
    }

    int t = 301;
    int ans = 0;
    while (t < 1201) {
        int nxt_t = t;
        for (int i = 0; i < n; i++) {
            if (flower[i].first <= t && flower[i].second > nxt_t) {
                nxt_t = flower[i].second;
            }
        }
        if (nxt_t == t) {
            cout << 0;
            return 0;
        }
        ans++;
        t = nxt_t;
    }

    cout << ans << "\n";
    
    return 0;
}