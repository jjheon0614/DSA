#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// using back-tracking
int n , s;
int arr[30];
int cnt = 0;
void func(int cur, int tot) {
    if (cur == n) {
        if (tot == s) cnt++;
        return;
    }

    func(cur + 1, tot);
    func(cur + 1, tot + arr[cur]);
}

int main() {
    cin >> n >> s;
    for (int i = 0; i < n ; i++) {
        cin >> arr[i];
    }

    func(0, 0);
    if (s == 0) cnt--;
    cout << cnt;
}


// using next_permutation()
// int main() {
//     int n, s;
//     int answer = 0;
//     cin >> n >> s;
    
//     vector<int> v;
//     for (int i = 0; i < n; i++) {
//         int num;
//         cin >> num;
//         v.push_back(num);
//     }

//     vector<bool> check(n);

//     for (int i = 1; i <= n; i++) {
//         fill(check.end() - i, check.end(), true);
//         do {
//             int sum = 0;
//             for (int j = 0; j < n; j++) {
//                 if (check[j]) {
//                     sum += v[j];
//                 }
//             }
//             if (sum == s) {
//                 answer++;
//             }
//         } while (next_permutation(check.begin(), check.end()));
//     }

//     cout << answer << "\n";


//     return 0;
// }