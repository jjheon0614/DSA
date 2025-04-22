#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<long long> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        long long num;
        cin >> num;

        v.push_back(num);
    }
    vector<long long> v_copy = v;

    sort(v_copy.begin(), v_copy.end());
    v_copy.erase(unique(v_copy.begin(), v_copy.end()), v_copy.end());

    for (int i = 0; i < N; i++) {
        auto it = lower_bound(v_copy.begin(), v_copy.end(), v[i]);
        cout << it - v_copy.begin() << ' ';
    }
    
    cout << "\n";

    return 0;
}