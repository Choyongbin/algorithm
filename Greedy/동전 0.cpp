#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k, sum= 0 , ans= 0;
	vector<int> arr;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	n--;
	while (sum != k) {
		if (sum + arr[n] > k)
			n--;
		else {
			sum += arr[n];
			ans++;
		}
	}
	cout << ans;
	return 0;
}