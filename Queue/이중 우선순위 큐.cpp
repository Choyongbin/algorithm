#include <iostream>
#include <set>

using namespace std;

int main() {
	int t, k, num;
	char cmd;
	cin >> t;
	for (int i = 0; i < t; i++) {
		multiset<int> ms;
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> cmd >> num;
			if (cmd == 'I') {
				ms.insert(num);
			}
			else if (cmd == 'D' && !ms.empty()) {
				if (num == -1) {
					ms.erase(ms.begin());
				}
				else if (num == 1) {
					auto iter = ms.end();
					iter--;
					ms.erase(iter);
				}
			}
		}
		if (ms.empty()) {
			cout << "EMPTY\n";
		}
		else {
			auto iter = ms.end();
			iter--;
			cout << *iter << ' ' << *ms.begin() << "\n";
		}
	}
	return 0;
}