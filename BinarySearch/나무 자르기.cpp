#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	long long n, m, num;
	vector<long long> tree;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num;
		tree.push_back(num);
	}
	sort(tree.begin(), tree.end());
	long long low = 1;
	long long high = tree[tree.size() - 1];

	long long ans = 0;
	while (low <= high) {
		long long target = 0;
		long long mid = (low + high) / 2;
		for (int i = 0; i < n; i++) {
			if(tree[i] > mid)
				target += tree[i] - mid;
		}
		if (target >=  m) {
			ans = max(ans, mid);
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << ans;
	return 0;
}