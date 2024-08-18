#include <iostream>
#include <string>

using namespace std;

int n;
string result = "";
bool finished = false;

void func(string str) {
    if (finished) return;
    int size = str.length();
    for (int i = 1; i <= size / 2; i++) {
        if (str.substr(size - i, i) == str.substr(size - 2 * i, i)) return;
    }

    if (size == n) {
        finished = true;
        result = str;
        return;
    }

    for (int i = 1; i <= 3; i++) {
        string copy = str;
        func(copy + to_string(i));
    }
}

int main() {
    
    cin >> n;
    string str = "";
    func(str);

    cout << result << "\n";
    
    return 0;
}