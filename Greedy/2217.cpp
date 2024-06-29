#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];


int main() {

    int n;
    cin >> n;

    for (int i = 0;i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int max = arr[n - 1];

    int weight;
    for (int i = n - 1; i >= 0; i--) {
        weight = arr[i] * (n - i);
        if (max < weight) {
            max = weight;
        }
    }

    cout << max;


    return 0;
}