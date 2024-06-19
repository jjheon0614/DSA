#include <iostream>

using namespace std;

int n, s;
int arr[100001];
int mn = 0x7fffffff;

int main() {

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int en = 0;
    int sum = arr[0];

    for (int st = 0; st < n; st++) {
        while (en < n && sum < s) {
            en++;
            if (en != n) sum += arr[en];
        }

        if (en == n) break;
        mn = min(mn, en - st + 1);
        sum -= arr[st];
    }

    if (mn == 0x7fffffff) mn = 0;
    

    cout << mn << "\n";

    return 0;
}