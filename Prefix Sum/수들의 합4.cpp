#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

long long psum[200001];

map<long long, long long >  m;

int main() {
	int n, k, i;
	long long ans = 0;

	cin>> n >> k;
	for (i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		psum[i] = psum[i - 1] + tmp;
	}

	for (i = 1; i <= n; i++) {
		if (psum[i] == k)
			ans++;
		ans += m[psum[i] - k];
		m[psum[i]]++;
	}

	cout << ans;
	return 0;
}