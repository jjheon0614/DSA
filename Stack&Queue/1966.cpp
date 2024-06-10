#include <iostream>
#include <queue>

using namespace std;

int main(void) {

    int num;
    cin >> num;
    vector<int> v;
    for (int i = 0; i < num; i++) {
        int N, M;
        cin >> N >> M;

        priority_queue<int> pq;
        queue<pair<int, int>> q;

        for (int i = 0; i < N; i++) {
            int important_num;
            cin >> important_num;
            pq.push(important_num);
            q.push({important_num, i});
        }
        
        int count = 1;
        while (1) {
            pair<int, int> front = q.front();
            q.pop();

            if (front.first == pq.top()) {
                if (front.second == M) {
                    v.push_back(count);
                    break;
                } else {
                    pq.pop();
                    count++;
                }
            } else {
                q.push(front);
            }
        }
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }

    return 0;
}