#include <iostream>

using namespace std;

int arr[301][301] = { 0 };
int dp[301][301] = { 0 };

int main() {
	int n, m, k, a, b, c, d;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + arr[i][j] - dp[i - 1][j - 1]; 
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> a >> b >> c >> d;
		cout << dp[c][d] - dp[c][b - 1] - dp[a - 1][d] + dp[a - 1][b - 1] << "\n";
	}
	return 0;
}