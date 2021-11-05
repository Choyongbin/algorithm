#include <iostream>

using namespace std;

int arr[1001] = { 0 };
int dp[1001] = { 0 };

int main() {
	int n, answer = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = arr[i];
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[i] < dp[j] + arr[i])
					dp[i] = dp[j] + arr[i];
			}
		}
		answer = max(answer, dp[i]);
	}
	cout << answer << "\n";
	return 0;
}