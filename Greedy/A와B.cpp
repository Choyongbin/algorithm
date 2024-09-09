#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
	string s, t;
	cin >> s;
	cin >> t;

	int s_len = s.size();
	int t_len = t.size();

	while (t_len > 0) {
		if (s_len == t_len) {
			if (s == t) {
				cout << 1;
				return 0;
			}
		}

		if (t[t_len - 1] == 'A') {
			t.pop_back();
			t_len--;
		}
		else {
			t.pop_back();
			reverse(t.begin(), t.end());
			t_len--;
		}
	}

	cout << 0;

	return 0;
}