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

    vector<int> result;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < v_copy.size(); j++) {
            if (v[i] == v_copy[j]) {
                result.push_back(j);

                break;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }

    cout << "\n";

    return 0;
}