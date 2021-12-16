#include <iostream>

using namespace std;

int main() {
	int k, n;
	long long arr[10001];
	long long maxNum = 0, left = 1, right = 0, ans = 0;
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		maxNum = max(arr[i], maxNum);
	}
	right = maxNum;

	while (left <= right) {
		long long mid = (left + right) / 2;
		long long temp = 0;
		for (int i = 0; i < k; i++) {
			temp += arr[i] / mid;
		}

		if (temp >= n) {
			left = mid + 1;
			ans = max(ans, mid);
		}
		else {
			right = mid - 1;
		}
	}
	cout << ans;
	return 0;
}