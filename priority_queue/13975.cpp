#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {

    int t;
    cin >> t;

    int k;

    for (int i = 0; i < t; i++) {
        cin >> k;
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        for (int j = 0; j < k; j++) {
            long long ch;
            cin >> ch;
            minHeap.push(ch);
        }

        long long result = 0;

        while (minHeap.size() != 1) {
            long long min = minHeap.top();
            minHeap.pop();
            long long secondMin = minHeap.top();
            minHeap.pop();

            long long sum = min + secondMin;
            result += sum;

            minHeap.push(sum);
        }

        cout << result << "\n";
    }

    return 0;
}