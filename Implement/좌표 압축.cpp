#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, temp;
	vector<int> a, ans;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		a.push_back(temp);
		ans.push_back(temp);
	}

	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());

	for (int i = 0; i < n; i++) {
		cout << lower_bound(a.begin(), a.end(), ans[i]) - a.begin() << " ";
	}

	return 0;
}