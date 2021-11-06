#include <iostream>
#include <vector>

using namespace std;

int dp[1001] = { 0 };
int arr[1001] = { 0 };
vector<int> list[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	vector<int> ans;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		list[i].push_back(arr[i]);
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[i] < dp[j] + 1) {
					list[i].clear();
					list[i] = list[j];
					list[i].push_back(arr[i]);
					dp[i] = dp[j] + 1;
				}
			}
		}
		if (ans.size() < list[i].size())
			ans = list[i];
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}