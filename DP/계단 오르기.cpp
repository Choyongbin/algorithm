#include <iostream>
using namespace std;

int dp[301] = { 0 };
int arr[301] = { 0 };

void solve(int n) {
	arr[0] = dp[0];
	arr[1] = dp[1] + dp[0];
	arr[2] = max(dp[2] + dp[0], dp[2]+ dp[1]);

	for (int i = 3; i <= n; i++) {
		arr[i] = max(dp[i] + dp[i - 1] + arr[i-3], dp[i] + arr[i - 2]);
	}
	cout << arr[n];
}

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		dp[i] = temp;
	}
	solve(n-1);

	return 0;
}