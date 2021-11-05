#include <iostream>

using namespace std;

int arr[1001] = { 0 };

int solve(int num) {
	if (arr[num] == 0) {
		return arr[num] = (solve(num - 1) + solve(num - 2)) % 10007;
	}
	return arr[num] % 10007;
}

int main() {
	int n;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 3;
	cin >> n;
	cout << solve(n);
	return 0;
}