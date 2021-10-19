#include <iostream>
#include <deque>
#include <cctype>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t,n;
	cin >> t;

	for (int i = 0; i < t; i++) {
		string cmd , arr;
		deque<int> dq;
		int flag = 0;
		cin >> cmd  >> n >> arr;
		for (int j = 0; i < arr.length(); j++) {
			if (isdigit(arr[j]) != 0) {
				dq.push_back(arr[j]);
			}
		}
		for (int j = 0; j < cmd.length(); j++) {
			if (cmd[j] == 'R') {
				deque<int> temp;
				for (int k = dq.size() - 1; k >= 0; k--) {
					temp.push_back(dq.back());
					dq.pop_back();
				}
				dq = temp;
			}
			else { //D
				if (dq.empty()) {
					cout << "error\n";
					flag = 1;
					break;
				}
				else {
					dq.pop_front();
				}
			}
		}
		if (flag == 0) {
			cout << "[";
			for (int j = 0; j < dq.size(); j++) {
				cout << dq[j];
				if (j != dq.size() - 1)
					cout << ",";
			}
			cout << "]\n";
		}
		


	}
	return 0;
}