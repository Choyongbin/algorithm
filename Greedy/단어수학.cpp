#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	int ans = 0;
	vector<int> alp(26);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		int cnt = pow(10,temp.length()-1);
		for (int j = 0; j < temp.length(); j++) {
			alp[temp[j] - 65] = alp[temp[j] - 65] + cnt;
			cnt = cnt / 10;
		}
	}
	sort(alp.begin(), alp.end(), greater<int>());
	for (int i = 0; i < alp.size(); i++) {
		ans += alp[i] * (9 - i);
	}
	cout << ans;
	
	return 0;
}