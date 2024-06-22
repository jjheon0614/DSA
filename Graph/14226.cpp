#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int s, ans = 1e9;
    cin >> s;
    
    queue<tuple<int, int, int> > q;
    q.push(make_tuple(1, 1, 1));
    bool v[1001] = {};
    
    while(!q.empty()) { //bfs
        int now = get<0>(q.front());
        int copy = get<1>(q.front());
        int value = get<2>(q.front());
        q.pop();
        
        if(now == s) { //원하는 개수로 맞추었다면 탐색 종료
            ans = value;
            break;
        }
        
        value++; //수행시간 1 증가
        
        if(now <= 1000 && !v[now]) { //다음단계로 단, 1000을 넘어가면 무조건 -1 만 반복하므로, 사전에 차단
            q.push(make_tuple(now+copy, copy, value)); //복사한 것을 붙여놓기
            if(now != copy) q.push(make_tuple(now, now, value)); //클립보드로 복사하기
            if(now > 2) q.push(make_tuple(now-1, copy, value)); //화면에서 1개 제거하기
            v[copy] = true; //방문확인
        }
    } 
    
    cout << ans << "\n";

    return 0;
}