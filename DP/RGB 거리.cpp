#include <iostream>
#include <cmath>

using namespace std;

int arr[1002][3] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, cost[3];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cost[0] >> cost[1] >> cost[2];
		arr[i][0] = min(arr[i - 1][1], arr[i - 1][2]) + cost[0];
		arr[i][1] = min(arr[i - 1][0], arr[i - 1][2]) + cost[1];
		arr[i][2] = min(arr[i - 1][0], arr[i - 1][1]) + cost[2];
	}
	cout << min(arr[n][0], min(arr[n][1], arr[n][2]));
	return 0;
}