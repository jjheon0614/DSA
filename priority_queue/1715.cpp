#include <iostream>
#include <queue>

using namespace std;


int main() {
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;

    while (n--) {
        int x;
        cin >> x;
        pq.push(x);
    }


    int total = 0;
    while (pq.size() != 1) {
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();

        total += first + second;
        pq.push(first + second);
    }

    cout << total << "\n";

    return 0;
}