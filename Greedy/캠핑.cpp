#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int l, v, p;
	int i = 0;
	while (1) {
		cin >> l >> p >> v;
		if (l == 0)
			break;
		cout << "Case " << ++i << ": " << min(v % p, l) + (v / p) * l << "\n";
	}
	return 0;
}