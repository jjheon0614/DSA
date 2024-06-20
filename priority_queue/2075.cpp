#include <iostream>
#include <queue>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n * n; i++) {
        int num;
        cin >> num;
        pq.push(num);

        if (n < (int) pq.size()) pq.pop();
    }

    cout << pq.top() << "\n";

    return 0;
}