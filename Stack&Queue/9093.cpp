#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string str;
        getline(cin, str);

        stringstream ss;
        ss.str(str);
        string word;
        while (ss >> word) {
            stack<char> s;

            for (int j = 0; j < word.size(); j++) {
                s.push(word[j]);
            }

            for (int j = 0; j < word.size(); j++) {
                cout << s.top();
                s.pop();
            }
            cout << " ";
        }
        cout << "\n";
    }

    return 0;
}