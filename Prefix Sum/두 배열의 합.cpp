#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t, n, m, num;
	vector<int> a, b;
	vector<long long> c, d;
	cin >> t >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		a.push_back(num);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;
		b.push_back(num);
	}
	for (int i = 0; i < n; i++) {
		c.push_back(a[i]);
		long long sum = a[i];
		for (int j = i+1; j < n; j++) {
			sum += a[j];
			c.push_back(sum);
		}
	}
	for (int i = 0; i < m; i++) {
		d.push_back(b[i]);
		long long sum = b[i];
		for (int j = i + 1; j < m; j++) {
			sum += b[j];
			d.push_back(sum);
		}
	}
	sort(d.begin(), d.end());
	long long result = 0;
	for (int i = 0; i < c.size(); i++) {
		long long lower = lower_bound(d.begin(), d.end(), t - c[i]) - d.begin();
		long long high = upper_bound(d.begin(), d.end(), t - c[i]) - d.begin();
		result += high - lower;
	}
	cout << result;
	return 0;
}