#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t, n, num;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int arr[1001];
		vector<int> dp;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < n; i++) {
			int sum = arr[i];
			dp.push_back(sum);
			for (int j = i + 1; j < n; j++) {
				sum += arr[j];
				dp.push_back(sum);
			}
		}
		cout << *max_element(dp.begin(), dp.end()) <<"\n";
	}
	return 0;
}