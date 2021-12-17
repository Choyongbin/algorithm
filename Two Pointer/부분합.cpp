#include <iostream>

using namespace std;

int arr[100001];

int main() {
	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int low = 0, high = 0, sum = arr[0], result = 1, ans =	987654321;

	while (low <= high && high < n) {
		if (sum < s) {
			sum += arr[++high];
			result++;
		}
		else if (sum > s) {
			ans = min(result, ans);
			result--;
			sum -= arr[low++];
			if (low > high && low < n) {
				high = low;
				sum = arr[low];
				result = 1;
			}
		}
		else if (sum == s) {
			ans = min(result, ans);
			result++;
			sum += arr[++high];
		}
	}
	if (ans == 987654321)
		cout << 0;
	else
		cout << ans;
	return 0;
}