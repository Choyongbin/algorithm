#include <iostream>
#include <algorithm>
using namespace std;

long long arr[100001];

int main() {
	int n;
	long long m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	int low = 0, high = 1;
	long long diff = 0, ans = 2000000001;
	while (low <= high && high < n) {
		diff = arr[high] - arr[low];
		if (diff > m) {
			ans = min(ans, diff);
			low++;
		}
		else if (diff < m) {
			high++;
		}
		else if (diff == m) {
			cout << m;
			return 0;
		}
	}
	cout << ans;
	return 0;
}
