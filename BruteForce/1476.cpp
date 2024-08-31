#include <iostream>

using namespace std;

int E, S, M;

int main() {
    cin >> E >> S >> M;

    if (E == S && E == M) {
        cout << E << "\n";

        return 0;
    }

    int count = 1;

    while(1){
        
        if((count - E) % 15 == 0 && (count - S) % 28==0 && (count - M) % 19 == 0){
            break;
        }
        else count++;
        
    }

    cout << count << "\n";

    return 0;
}