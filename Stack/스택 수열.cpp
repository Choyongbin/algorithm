#include <iostream>
#include <stack>

using namespace std;

int main() {
	int n, temp;
	stack<int> st;
	string ans = "";
	cin >> n;
	int now = 0;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp > now) {
			while (temp > now) {
				st.push(++now);
				ans += '+';
			}
			st.pop();
			ans += '-';
		}
		else {
			int flag = 0;
			if (!st.empty()) {
				if (st.top() == temp) {
					flag = 1;
				}
				st.pop();
				ans += '-';
			}
			if (flag == 0) {
				cout << "NO\n";
				return 0;
			}
		}
	}
	for (auto i : ans)
		cout << i << "\n";
	return 0;
}