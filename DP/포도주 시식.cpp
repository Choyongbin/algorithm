#include <iostream>
#include <vector>
using namespace std;

int dp[10001] = { 0 };
int arr[10001] = { 0 };

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr[i] = temp;
	}

	dp[0] = arr[0];
	dp[1] = arr[1] + arr[0];

	for (int i = 2; i < n; i++) {
		dp[i] = dp[i - 1];
		dp[i] = max(dp[i], dp[i - 2] + arr[i]);
		dp[i] = max(dp[i], dp[i - 3] + arr[i - 1] + arr[i]);
	}

	cout << dp[n-1];
	return 0;
}