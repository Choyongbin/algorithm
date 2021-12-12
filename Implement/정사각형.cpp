#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int dist(int x1, int y1, int x2, int y2) {
	return	pow(x1 - x2, 2) + pow(y1 - y2, 2);
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b;
		vector<pair<int, int>> v;
		vector<int> ans;
		for (int i = 0; i < 4; i++) {
			cin >> a >> b;
			v.push_back({ a,b });
		}
		for (int i = 0; i < 4; i++) {
			for (int j = i + 1; j < 4; j++) {
				ans.push_back(dist(v[i].first, v[i].second, v[j].first, v[j].second));
			}
		}
		sort(ans.begin(), ans.end());
		if (ans[0] == ans[1] && ans[1] == ans[2] && ans[2] == ans[3] && ans[4] == ans[5])
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
		
	}
	return 0;
}