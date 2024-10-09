#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> views;
vector<int> likes;

int main() {

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
	int num;
	cin >> num;
	views.push_back(num);
  }

  for (int i = 0; i < n; i++) {
	int num;
	cin >> num;
	likes.push_back(num);
  }

	for (int i = 0; i < n; i++) {
		cout << views[i] << " ";
	}

	sort(views.begin(), views.end());
	sort(likes.begin(), likes.end());

	int result = 0;

	int view_index = 0;
	int like_index = 0;

	for (int i = 0; i < n; i++) {
		
	}



  return 0;
}