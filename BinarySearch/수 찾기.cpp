#include <iostream>
#include <set>
#include <algorithm>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, num;
	set<int> arr;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.insert(num);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;
		auto it = arr.find(num);
		if (it == arr.end())
			cout << 0 << "\n";
		else
			cout << 1 << "\n";
	}
	return 0;
}