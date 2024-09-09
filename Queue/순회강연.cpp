#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int, int>> arr;
int result = 0;

int main() {
	int n, p, d;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> p >> d;
		arr.push_back({ d,p });
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