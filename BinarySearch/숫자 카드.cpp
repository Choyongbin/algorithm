#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, num;
	set<int> s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		s.insert(num);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;
		if (s.find(num) == s.end())
			cout << 0 << " ";
		else
			cout << 1 << " ";
	}
	return 0;
}