#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> top;
vector<int> bottom;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, h, k;
	cin >> n >> h;
	for (int i = 0; i < n; i++) {
		cin >> k;
		if (i % 2 == 0)
			bottom.push_back(k);
		else
			top.push_back(k);
	}
	sort(bottom.begin(), bottom.end());
	sort(top.begin(), top.end());
	int result = INT_MAX;
	int cnt = 1;
	int botSize = bottom.size();
	int topSize = top.size();
	for (int i = 1; i <= h; i++) {
		int temp = botSize - (lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin());
		temp += topSize - (upper_bound(top.begin(), top.end(), h-i) - top.begin());

		if (result == temp) {
			cnt++;
		}
		else if (result > temp) {
			result = temp;
			cnt = 1;
		}
	}

	cout << result << " " << cnt;
	return 0;
}