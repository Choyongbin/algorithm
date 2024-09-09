#include <iostream>

using namespace std;

int arr[1 << 20];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a, index, val;

	while (cin >> a) {
		if (a == NULL)
			break;
		index = a / 32;
		val = 1 << (a % 32);
		if (!(arr[index] & val)) {
			arr[index] += val;
			cout << a << " ";
		}
	}
	return 0;
}