#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string n;
	while (1) {
		cin >> n;
		if (n == "0")
			break;
		int first = 0;
		int last = n.length() - 1;
		while (1) {
			if (last <= first) {
				cout << "yes\n";
				break;
			}
			if (n[first] == n[last]) {
				first++;
				last--;
			}
			else {
				cout << "no\n";
				break;
			}
		}
	}
	return 0;
}