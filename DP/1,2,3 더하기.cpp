#include <iostream>

using namespace std;

int arr[12] = { 0 };

int solve(int num) {
	if (arr[num] == 0) {
		return arr[num] = solve(num - 1) + solve(num - 2) + solve(num - 3);
	}
	else {
		return arr[num];
	}
}

int main() {
	int t,num;
	cin >> t;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for (int i = 0; i < t; i++) {
		cin >> num;
		cout << solve(num) << "\n";
	}
	return 0;
}