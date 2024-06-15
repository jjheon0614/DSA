#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    long long n, m;
    cin >> n >> m;

    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    int low = 1;
    int high = v[0];
    int max;


    while (low <= high) {
        int sum = 0;
        int mid = (low + high) / 2;

        for (int i = 0; i < n; i++) {
            sum += (int)(v[i] / mid);
        }

        if (sum >= m) {
            if (max < mid) max = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << max << "\n";

    return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    int low = 0;
    int high = v[0];
    int max;


    while (low <= high) {
        int sum = 0;
        int mid = (low + high) / 2;

        for (int i = 0; i < n; i++) {
            sum += v[i] / mid;
        }

        if (sum >= m) {
            max = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << max << "\n";

    return 0;
}