#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	cin >> t;

	for (int i = 0; i < t; i++) {
		string cmd, arr, temp;
		deque<int> dq;
		int flag = 0;
		bool left = true;
		cin >> cmd >> n >> arr;
		for (int j = 0; j < arr.length(); j++) {
			if (arr[j] == '[')
				continue;
			else if (arr[j] >= '0' && arr[j] <= '9')
				temp += arr[j];
			else {
				if (!temp.empty()) {
					dq.push_back(stoi(temp));
					temp.clear();
				}
			}
		}
		for (int j = 0; j < cmd.length(); j++) {
			if (cmd[j] == 'R') {
				left = !left;
			}
			else { //D
				if (dq.empty()) {
					cout << "error\n";
					flag = 1;
					break;
				}
				else {
					if (left)
						dq.pop_front();
					else
						dq.pop_back();
				}
			}
		}
		if (flag == 0) {
			cout << "[";
			if (left) {
				for (int j = 0; j < dq.size(); j++) {
					cout << dq[j];
					if (j != dq.size() - 1)
						cout << ",";
				}
			}
			else {
				for (int j = dq.size()-1; j >=0; j--) {
					cout << dq[j];
					if (j != 0)
						cout << ",";
				}
			}
			cout << "]\n";
		}



	}
	return 0;
}