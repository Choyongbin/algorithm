#include <iostream>
#include <deque>

using namespace std;

int main() {
	int n, m, a;
	int ans = 0;
	deque<int> dq;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}

	for (int i = 0; i < m; i++) {
		int left = 0, right = 0;
		cin >> a;
		for (int i = 0; i < dq.size(); i++) {
			if (dq[i] == a) {
				left = i;
				right = dq.size() - i;
				break;
			}
		}

		if (left <= right) {
			while (true) {
				if (dq.front() == a)
					break;
				dq.push_back(dq.front());
				dq.pop_front();
				ans++;
			}
			dq.pop_front();
		}
		else {
			ans++;
			while (true) {
				if (dq.back() == a)
					break;
				dq.push_front(dq.back());
				dq.pop_back();
				ans++;
			}
			dq.pop_back();
		}

	}

	cout << ans;
	return 0;
}