#include <iostream>

using namespace std;

long long arr[100001];
long long dp[100002];

int main() {
	long long n, num;
	long long answer = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0] = arr[0];
	answer = dp[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		answer = max(answer, dp[i]);
	}
	cout << answer;
	return 0;
}