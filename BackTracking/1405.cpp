#include <iostream>

using namespace std;

long double N, w[4];
int visited[30][30];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

long double track(int y, int x, long double p, int cnt) {
    if (cnt == N || p == 0) return p;
    long double sum = 0;

    for (int i = 0; i < 4; i++) {
        if (visited[y + dy[i]][x + dx[i]]) continue;

        visited[y+ dy[i]][x + dx[i]]++;
        sum += track(y + dy[i], x + dx[i], p * w[i], cnt + 1);
        visited[y + dy[i]][x + dx[i]]--;
    }

    return sum;
}

int main() {

    cin >> N >> w[0] >> w[1] >> w[2] >> w[3];

    for (int i = 0; i < 4; i++) w[i] /= 100;


    visited[15][15]++;
    cout.precision(10);
    cout << track(15, 15, 1, 0) << "\n";


    return 0;
}