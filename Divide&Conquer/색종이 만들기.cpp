#include <iostream>

using namespace std;

int arr[128][128] = { 0 };
int blue = 0;
int white = 0;

void solve(int x, int y, int size) {
	int a = arr[x][y];
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (arr[i][j] != a) {
				solve(x, y + size / 2, size / 2);
				solve(x + size / 2, y, size / 2);
				solve(x, y, size / 2);
				solve(x + size / 2, y + size / 2, size / 2);
				return;
			}
		}
	}
	if (a == 0) white++;
	else blue++;
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
	cout << white << "\n" << blue;
	return 0;
}