#include <queue>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int main() {
	int k, n;
	long long num;
	vector<long long> sosu;
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	map<long long, bool> check;
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> num;
		sosu.push_back(num);
	}

	pq.push(1);
	check[1] = 1;
	long long maxNum = 0;

	for (int i = 0; i < n; i++) {
		long long x = pq.top();
		pq.pop();


		for (int j = 0; j < sosu.size(); j++) {
			long long nx = x * sosu[j];

			if (check.count(nx))
				continue;
			if (pq.size() > n && maxNum <= nx)
				continue;
			pq.push(nx);
			check[nx] = 1;
			maxNum = max(maxNum, nx);

		}
	}
	cout << pq.top();
	return 0;

}