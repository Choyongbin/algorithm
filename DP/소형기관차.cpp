#include <iostream>
#include <algorithm>
using namespace std;

int arr[50001];
int dp[4][50001];

int main() {
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int temp; 
		cin >> temp;
		arr[i] = arr[i - 1] + temp;
	}
	cin >> m;

	for (int i = 1; i <= 3; i++) {
		for (int j = i * m; j <= n; j++) {
			dp[i][j] = max(dp[i][j - 1], (arr[j] - arr[j - m]) + dp[i - 1][j - m]);
		}
	}
	cout << dp[3][n];
	return 0;
}