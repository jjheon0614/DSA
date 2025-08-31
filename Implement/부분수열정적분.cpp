#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer(ranges.size());
    
    vector<int> graphs;
    
    while (k != 1) { // 꼭짓점 구하기
        graphs.push_back(k);
        if (k % 2 == 0) {
            k /= 2;
        } else {
            k = k * 3 + 1;
        }
    }
    graphs.push_back(1);
    int n = graphs.size();
    
    vector<double> surfaces(n - 1);
    
    for (int i = 0; i < n - 1; i++) { // 각각의 면적 구하기
        surfaces[i] = (graphs[i] + graphs[i + 1]) / 2.0;
    }
    
    for (int i = 0; i < ranges.size(); i++) {
        int a = ranges[i][0];
        int b = ranges[i][1];
        
        if (n + b - 1 >= a) {
            for (int j = a; j < n + b - 1; j++) {
                answer[i] += surfaces[j];
            }
        } else {
            answer[i] = -1;
        }
    }
    
    return answer;
}