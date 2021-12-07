#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<long long> arr) {
	sort(arr.begin(), arr.end());
	long long minimum = arr[0]; // 이전

	arr.erase(arr.begin() + 0);
	for (int i = 0; i < arr.size(); i++) {
		arr[i] = arr[i] - minimum;
	}
	sort(arr.begin(), arr.end());
	long long minimum1 = arr[0]; // 이후

	if (minimum1 >= minimum && arr.size() >= 2) {
		solve(arr);
	}
	else {
		if (minimum1 > minimum)
			cout << minimum1 << "\n";
		else
			cout << minimum << "\n";
		return;
	}
}

int main() {
	int t,n;
	long long a;
	cin >> t;
	for (int i = 0; i < t; i++) {
		vector<long long> arr;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> a;
			arr.push_back(a);
		}
		if (n < 2) {
			cout << arr[0] << "\n";
			continue;
		}
		solve(arr);
	}
	return 0;
}