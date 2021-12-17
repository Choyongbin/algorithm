#include <iostream>

using namespace std;

int arr[10001];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int low = 0, high = 0, sum = arr[0], result = 0;

	while (low <= high && high <= n - 1) {

		if (sum > m) {
			sum -= arr[low++];
			if (low > high && low <= n - 1) {
				high = low;
				sum = arr[low];
			}
		}
		else if (sum < m) {
			sum += arr[++high];
		}
		else if (sum == m) {
			result++;
			sum += arr[++high];
		}
	}
	cout << result;
	return 0;
}