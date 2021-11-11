#include <iostream>

using namespace std;

int arr[1025][1025] = { 0 };
int dp[1025][1025] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, a, b, c, d;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + arr[i][j] - dp[i - 1][j - 1];
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c >> d;
		cout << dp[c][d] - dp[c][b - 1] - dp[a - 1][d] + dp[a - 1][b - 1] << "\n";
	}
	return 0;
}