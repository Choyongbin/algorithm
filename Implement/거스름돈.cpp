#include <iostream>

using namespace std;

int main() {
	int n, ans = 0;
	cin >> n;
	while (n > 0) {
		if (n % 5 == 0) {
			ans += n / 5;
			break;
		}
		n -= 2;
		ans++;
	}
	if (n < 0)
		cout << -1;
	else
		cout << ans;
	return 0;
}