#include <iostream>

using namespace std;

int dp[1001] = { 0 };
int arr[1001] = { 0 };

int main() {
	int n, answer = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		int min = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (min < dp[j])
					min = dp[j];
			}
		}
		dp[i] = min + 1;
		answer = max(answer, dp[i]);
	}
	cout << answer << "\n";
	return 0;
}