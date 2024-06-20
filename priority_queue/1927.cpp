#include <iostream>
#include <queue>

using namespace std;


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    priority_queue<unsigned int, vector<unsigned int>, greater<>> pq;
    while (n--) {
        unsigned int x;
        cin >> x;

        if (x == 0) {
            if (pq.size() == 0) {
                cout << "0\n";
            } else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        } else {
            pq.push(x);
        }
    }

    return 0;
}