#include <iostream>

using namespace std;

long long arr[101][11];
#define mod 1000000000

int main() {
	int n;
	long long ans = 0;
	cin >> n;
	for (int i = 1; i <= 9; i++) {
		arr[1][i] = 1;
	}
	arr[1][0] = 0;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0)
				arr[i][j] = arr[i - 1][j + 1] % mod;
			else if (j == 9)
				arr[i][j] = arr[i - 1][j - 1] % mod;
			else
				arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % mod;
		}
	}
	for (int i = 0; i < 10; i++) {
		ans = ans + arr[n][i];
	}
	cout << ans % mod;
	return 0;
}