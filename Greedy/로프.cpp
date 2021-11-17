#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, ans = 0;
	vector<int> a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		a.push_back(num);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		ans = max(ans, a[i] * (n - i));
	}
	cout << ans;
	return 0;
}