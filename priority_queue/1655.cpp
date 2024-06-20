#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int t;
    while (n--) {
        cin >> t;

        if (maxHeap.size() <= minHeap.size()) {
            maxHeap.push(t);
        } else {
            minHeap.push(t);
        }
        
        if (!minHeap.empty() && minHeap.top() < maxHeap.top()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        cout << maxHeap.top() << "\n";
    }

    return 0;
}