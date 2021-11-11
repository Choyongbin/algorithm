#include <iostream>

using namespace std;
int arr[100001];
int dp[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, sum=0, a, b, m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum += arr[i];
		dp[i] = sum;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << dp[b] - dp[a-1] << "\n";
	}

	return 0;
}