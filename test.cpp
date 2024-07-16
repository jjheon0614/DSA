#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    int* Node;
};

//  first node -> second -> third -> forth

// store  value of the second node
// first node connects with the third => first -> third -> forth
// second value -> second -> first -> third -> forth

int main() {


    vector<int> v;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);


    }

    for (int i = 0; i < n; i += 2) {
        // if (i % 2 == 0) {
        //     if (i == n - 1) break;

            
        // }

        if (i == n - 1) break;

        int tmp = v[i];
        v[i] = v[i + 1];
        v[i + 1] = tmp;

    }

    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }


    return 0;
}