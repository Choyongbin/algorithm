#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> arr;
priority_queue<int, vector<int>, greater<int>> pq;
int result = 0;

int main() {
	int n, p, q;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> p >> q;

		arr.push_back({ p,q });
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++) {
		pq.push(arr[i].second);
		result += arr[i].second;

		if (pq.size() > arr[i].first) {
			result -= pq.top();
			pq.pop();
		}
	}

	cout << result;

	return 0;
}