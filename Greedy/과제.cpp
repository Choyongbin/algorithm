#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, result = 0;
	vector<pair<int, int>> v;
	int arr[1001] = { 0 };
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ b,a });
	}

	sort(v.begin(), v.end(), greater<pair<int,int>>());
	
	for (int i = 0; i < n; i++) {
		int end = v[i].second;
		
		while (end >= 1) {
			if (arr[end] == 0) {
				arr[end] = v[i].first;
				break;
			}
			else {
				--end;
			}
		}
	}

	for (int i = 0; i < 1001; i++) {
		result += arr[i];
	}
	cout << result;
	return 0;
}