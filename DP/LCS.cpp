#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main() {
	string a, b;

	cin >> a >> b;

	int size1 = a.length();
	int size2 = b.length();

	for (int i = 1; i <= size1; i++) {
		for (int j = 1; j <= size2; j++) {
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[size1][size2] << "\n";
	return 0;
}