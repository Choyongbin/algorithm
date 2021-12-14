#include <iostream>

using namespace std;

int arr[1001][1001];

int main() {
	int n, m, answer = 0;
	string c;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> c;
		for (int j = 0; j < c.length(); j++) {
			arr[i][j + 1] = c[j] - '0';
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] != 0) {
				arr[i][j] = min(min(arr[i-1][j-1], arr[i - 1][j]), arr[i][j - 1]) + 1;
				answer = max(answer, arr[i][j]);
			}
		}
	}
	cout << answer * answer;
	return 0;
}