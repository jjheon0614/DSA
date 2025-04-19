#include <iostream>
#include <vector>

using namespace std;

int n;
vector<long long> v;
vector<long long> op;
long long result_min = 1000000000;
long long result_max = -1000000000;


void func(int result, int index) {
    if (index == v.size() - 1) {
        if (result <= result_min) {
            result_min = result;
        }
        
        if (result >= result_max) {
            result_max = result;
        }

        return;
    }

    for (int i = 0; i < 4; i++) {
        if (op[i] > 0) {
            if (i == 0) {
                result = result + v[index + 1];
            } else if (i == 1) {
                result = result - v[index + 1];
            } else if (i == 2) {
                result = result * v[index + 1];
            } else {
                result = result / v[index + 1];
            }
            op[i]--;
            func(result, index + 1);
            op[i]++;
            if (i == 0) {
                result = result - v[index + 1];
            } else if (i == 1) {
                result = result + v[index + 1];
            } else if (i == 2) {
                result = result / v[index + 1];
            } else {
                result = result * v[index + 1];
            }
        }
    }
}

int main () {
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long num;
       cin >> num;

       v.push_back(num);
    }

    for (int i = 0; i < 4; i++) {
        int operator_num;
        cin >> operator_num;

        op.push_back(operator_num);
    }

    func(v[0], 0);

    cout << result_max << "\n" << result_min << "\n";

    return 0;
}