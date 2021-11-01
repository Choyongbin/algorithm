#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, ans = 0;
	vector<int> arr;
	cin >> n; 

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++) {
		ans += arr[i] * (n - i);
	}
	cout << ans;
	return 0;
}