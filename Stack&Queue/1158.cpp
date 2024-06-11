#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {

    int N, K;
    cin >> N >> K;
    queue<int> q;

    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    vector<int> v;
    int count = 1;
    while (!q.empty()) {
        int num = q.front();
        q.pop();
        if (count == K) {
            v.push_back(num);
            count = 1;
            continue;
        } else {
            count++;
            q.push(num);
        }
    }

    cout << '<';
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            cout << v[i];
        } else {
            cout << ", " << v[i];
        }
    }
    cout << "\n";


    return 0;
}