#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    string cmp;

    getline(cin, str);
    getline(cin, cmp);

    int result = 0;

    for (int i = 0; i < str.length(); i++) {
        if (cmp.length() > str.length() - i) {
            break;
        }

        string tmp = str.substr(i, cmp.length());
        if (tmp == cmp) {
            result++;
            i += cmp.length() - 1;
        }
    }

    cout << result << "\n";

    return 0;
}