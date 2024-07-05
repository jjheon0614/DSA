#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int b[105][100005]={0,};
vector<pair<int, int>> v;

int main() {

    cin >> n >> k;
    
    
    v.push_back({0, 0});

    for (int i = 0; i < n; i++) {
        int weight, val;
        cin >> weight >> val;
        v.push_back({weight, val});
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            int first = v[i].first;
            int second = v[i].second;

            if (first <= j) {
                if ((second + b[i - 1][j - first] > b[i - 1][j])) {
                    b[i][j] = second + b[i - 1][j - first];
                } else {
                    b[i][j] = b[i - 1][j];
                }
            } else {
                b[i][j] = b[i - 1][j];
            }
        }
    }

    cout << b[n][k] << "\n";

    return 0;
}