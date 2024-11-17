#include <iostream>
#include <map>

using namespace std;

int main(void) {

    int n;
    cin >> n;

    map<long long, long long> m;

    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;

        m[num]++;
    }

    long long result = 0;
    int max = 0;

    for (auto num: m) {
        if (max < num.second) {
            max = num.second;
            result = num.first;
        }
    }

    cout << result << "\n";

    return 0;
}