#include <vector>
#include <unordered_map>
#include <iostream>

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
   	
    vector<int> answer;
    // find 연산을 위한 부모-자식 연결
    unordered_map<string, string> parent;
    // 수익 결과 저장
    unordered_map<string, int> res;
    // 부모-자식 관계 정립
    for (int i = 0; i < referral.size(); ++i)
        parent[enroll[i]] = referral[i];

    for (int i = 0; i < seller.size(); ++i)
    {
        // 원금만큼의 이익
        int point = amount[i] * 100;
        // 판매자 이름
        string me = seller[i];
        // 원금 저장
        res[me] += point;

        // 원금 수익률 10% 회수(내 위에 고용주가 없거나 수익을 뗄 돈이 없을 경우)
        while (me != "-" && point > 9)
        {
            point /= 10;
            res[parent[me]] += point;
            res[me] -= point;
            me = parent[me];
        }
    }
    // 누가 얼마를 벌었는 지 출력에 맞게 push
    for (int i = 0; i < enroll.size(); ++i)
        answer.push_back(res[enroll[i]]);
        
    return answer;
}