#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dist[200002];
int track[200002];
int n, k;

int main() {
    cin >> n >> k;

    fill(dist, dist + 200002, -1);

    queue<int> q;
    q.push(n);
    dist[n] = 0;
    track[n] = n;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int nxt: {cur - 1, cur + 1, 2 * cur}) {
            if (nxt < 0 || nxt > 200002 || dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            track[nxt] = cur;
            q.push(nxt);
        }
    }

    cout << dist[k] << "\n";
    deque<int> dq = {k};
    while (dq.front() != n) {
        dq.push_front(track[dq.front()]);
    }

    for (int p : dq) cout << p << ' ';

    return 0;
}