#include <iostream>

using namespace std;

int arr[2200][2200] = { 0 };
int a1 = 0, a2 = 0, a3 = 0;

void solve(int x, int y, int size) {
	int a = arr[x][y];
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (a != arr[i][j]) {
				solve(x, y, size / 3);
				solve(x + size / 3, y, size / 3);
				solve(x + size * 2 / 3, y, size / 3);
				solve(x, y + size / 3, size / 3);
				solve(x + size / 3, y + size / 3, size / 3);
				solve(x + size * 2 / 3, y + size / 3, size / 3);
				solve(x, y + size * 2 / 3, size / 3);
				solve(x + size / 3, y + size*2 / 3, size / 3);
				solve(x + size * 2 / 3, y + size * 2 / 3, size / 3);
				return;
			}
		}
	}
	if (a == -1) a1++;
	else if (a == 0) a2++;
	else a3++;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	solve(0, 0, n);
	cout << a1 << "\n" << a2 << "\n" << a3;
	return 0;
}