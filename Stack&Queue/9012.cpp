#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main() {

    int T;
    cin >> T;

    vector<string> v;

    for (int i = 0; i < T; i++) {
        string str;
        cin >> str;
        stack<char> s;
        bool check = false;

        for (int j = 0; j < str.length(); j++) {
            if (str[j] == '(') {
                s.push('(');
            } else {
                if (s.size() > 0) {
                    s.pop();
                } else {
                    v.push_back("NO");
                    check = true;
                    break;
                }
            }
        }
        if (check) {
            continue;
        }

        if (s.size() > 0) {
            v.push_back("NO");
        } else {
            v.push_back("YES");
        }
    }

    for (int i = 0; i < T; i++) {
        cout << v[i] << "\n";
    }

    return 0;
}