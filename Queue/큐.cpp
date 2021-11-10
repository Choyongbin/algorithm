#include <iostream>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, num;
	string cmd;
	deque<int> dq;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> num;
			dq.push_back(num);
		}
		else if (cmd == "pop") {
			if (dq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if (cmd == "size") {
			cout << dq.size() << "\n";
		}
		else if (cmd == "empty") {
			if (dq.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (cmd == "front") {
			if (dq.empty())
				cout << "-1\n";
			else
				cout << dq.front() << "\n";
		}
		else {
			if (dq.empty())
				cout << "-1\n";
			else
				cout << dq.back() << "\n";
		}
	}
	return 0;
}