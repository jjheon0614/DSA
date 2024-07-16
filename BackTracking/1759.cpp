#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main () {

    int l, c;
    cin >> l >> c;

    vector<bool> v(c);
    vector<char> chars(c);
    fill(v.end() - c + l, v.end(), true);

    for (int i = 0; i < c; i++) {
        cin >> chars[i];
    }

    sort(chars.begin(), chars.end());

    do {
        string str = "";
        int count1 = 0;
        int count2 = 0;
        for (int i = 0; i < c; i++) {
            if (v[i] == false) {
                if (chars[i] == 'a' || chars[i] == 'e' || chars[i] == 'i' || chars[i] == 'o' || chars[i] == 'u') {
                    count1++;
                } else {
                    count2++;
                }
                str += chars[i];
            }
        }
        if (count1 >= 1 && count2 >= 2) {
            cout << str << "\n";
        }

    } while (next_permutation(v.begin(), v.end()));


    return 0;
}