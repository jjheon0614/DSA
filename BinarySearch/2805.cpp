#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long max, n, height;

    cin >> n >> height;
    vector<long long> v;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());
    int small = 0;
    int high = v[n - 1];

    while (small <= high) {
        long long sum = 0;
        long long mid = (small + high) / 2;

        for (int i = 0; i < n; i++) {
            if (v[i] > mid) {
                sum += v[i] - mid;
            }
        }

        if (sum >= height) {
            max = mid;
            small = mid + 1;
        } else if (sum < height) {
            high = mid - 1;
        }
    }

    cout << max;

    return 0;
}