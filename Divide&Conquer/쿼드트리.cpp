#include <iostream>

using namespace std;

int arr[64][64] = { 0 };

void solve(int x, int y, int size) {
	int a = arr[x][y];
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (a != arr[i][j]) {
				cout << "(";
				solve(x, y, size / 2);
				solve(x, y + size / 2, size / 2);
				solve(x + size / 2, y, size / 2);
				solve(x + size / 2, y + size / 2, size / 2);
				cout << ")";
				return;
			}
		}
	}
	cout << a;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.length(); j++) {
			arr[i][j] = temp[j] - '0';
		}
	}
	solve(0, 0, n);

	return 0;
}