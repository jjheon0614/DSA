#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    
    vector<int> negative;
    vector<int> positive;
    bool zero = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            negative.push_back(arr[i]);
        } else if (arr[i] == 0) {
            zero = true;
        } else {
            positive.push_back(arr[i]);
        }
    }

    int sum = 0;
    for (int i = positive.size() - 1; i >= 0; i--) {
        if (i == 0) {
            sum += positive[i];
        } else {
            if (positive[i] == 1 && positive[i - 1] == 1) {
                sum += positive[i] + positive[i - 1];
                i--;
                continue;
            }
            sum += positive[i] * positive[i - 1];
            i--;
        }
    }

    for (int i = 0; i < negative.size(); i++) {
        if (zero && i == 0) {
            continue;
        }

        if (i != negative.size() - 1) {
            sum += negative[i] * negative[i + 1];
            i++;
        } else {
            sum += negative[i];
        }
    }


    cout << sum << "\n";

    return 0;
}