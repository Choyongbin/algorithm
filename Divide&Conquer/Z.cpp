#include <iostream>

using namespace std;

int n, r, c;
int ans = 0;

void solve(int x, int y, int size) {
	if (x == c && y == r) {
		cout << ans;
		return;
	}
	if (c < x + size && c >= x && r < y + size && r >= y) {
		solve(x, y, size / 2);
		solve(x + size / 2, y, size / 2);
		solve(x, y + size / 2, size / 2);
		solve(x + size / 2, y + size / 2, size / 2);
	}
	else
		ans += size * size;
}

int main() {
	cin >> n >> r >> c;
	solve(0, 0, 1<<n);
	return 0;
}