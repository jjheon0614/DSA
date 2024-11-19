#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;

        cin >> a >> b;
        vector<int> arrA, arrB;

        for (int j = 0; j < a; j++) {
            int num;
            cin >> num;
            arrA.push_back(num);
        }

        for (int j = 0; j < b; j++) {
            int num;
            cin >> num;
            arrB.push_back(num);
        }

        int result = 0;

        sort(arrA.begin(), arrA.end());
        sort(arrB.begin(), arrB.end(), greater<int>());

        for (int j = 0; j < a; j++) {
            if (arrA[j] > arrB[0]) {
                result += arrB.size();
            } else {
                
            }
            for (int k = 0; k < b; k++) {
                if (arrA[j] > arrB[k]) {
                    result++;
                }
            }
        }

        cout << result << "\n";
    }


    return 0;
}