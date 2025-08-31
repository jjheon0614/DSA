#include <iostream>
#include <vector>

using namespace std;

int main(void) { 
	vector<int> arr = { 1,1,2,3 }; 
	do { 
		for (int i = 0; i < arr.size(); ++i) { 
			cout << arr[i]; 
		} 
		cout << '\n'; } 
	while (next_permutation(arr.begin(), arr.end())); 
	
	return 0; 
}