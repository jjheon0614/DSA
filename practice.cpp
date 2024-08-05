#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int max = n / 5;

    int result = -1;
    for (int i = max; i >= 0; i--) {
        int copy = n;

        int rest = copy - i * 5;

        if (rest % 3 == 0) {
            result = i + rest / 3;
            break;
        }
    }

    cout << result << "\n";

    return 0;
}