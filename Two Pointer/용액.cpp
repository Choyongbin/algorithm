#include <iostream>
#include <cmath>
using namespace std;

int arr[100001];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int low = 0, high = n - 1, left = 0, right = 0, sum = 2000000001, ansLeft = 0, ansRight = 0;
	while (low < high) {
		left = arr[low];
		right = arr[high];

		if (abs(left + right) < sum) {
			sum = abs(left + right);
			ansLeft = left;
			ansRight = right;
		}
		if (left + right < 0)
			low++;
		else
			high--;
	}
	if (ansLeft > ansRight)
		cout << ansRight << " " << ansLeft;
	else
		cout << ansLeft << " " << ansRight;
	return 0;
}