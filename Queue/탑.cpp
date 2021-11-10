#include <iostream>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	deque<pair<int, int>> dq; //index, num
	int n, num;
	cin >> n; 

	for (int i = 0; i < n; i++) {
		cin >> num;
		while (!dq.empty()) {
			if (dq.back().second >= num) {
				cout << dq.back().first << " ";
				break;
			}
			dq.pop_back();
		}
		if (dq.empty())
			cout << "0 ";
		dq.push_back(make_pair(i + 1, num));
	}
	return 0;
}

/*
// 시간 초과
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, num;
	deque<int> dq, temp, ans;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> num;
		dq.push_back(num);
	}
	while (!dq.empty()) {
		int now = dq.back();
		dq.pop_back();
		while (!dq.empty()) {
			if (now <= dq.back()) {
				ans.push_front(dq.size());
				break;
			}
			temp.push_back(dq.back());
			dq.pop_back();
		}
		if (dq.empty())
			ans.push_front(0);
		while (!temp.empty()) {
			dq.push_back(temp.back());
			temp.pop_back();
		}
	}
	
	while (!ans.empty()) {
		cout << ans.front() << " ";
		ans.pop_front();
	}
	
	return 0;
}
*/