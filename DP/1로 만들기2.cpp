#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arr(n + 1);
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i <= n; i++) {
		arr[i] = arr[i - 1] + 1;
		if (i % 3 == 0)
			arr[i] = min(arr[i], arr[i / 3] + 1);
		if (i % 2 == 0)
			arr[i] = min(arr[i], arr[i / 2] + 1);
	}
	cout << arr[n] - 1 << "\n";
	
	while (n != 0) {
		cout << n << " ";
		if (arr[n] == arr[n - 1] + 1)
			n = n - 1;
		else if (n % 3 == 0 && arr[n] == arr[n / 3] + 1)
			n = n / 3;
		else if (n % 2 == 0 && arr[n] == arr[n / 2] + 1)
			n = n / 2;
	}
	
	return 0;
}