#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, num;
	string cmd;
	vector<int> arr;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == "add") {
			cin >> num;
			auto it = find(arr.begin(), arr.end(), num);
			if(it == arr.end())
				arr.push_back(num);
		}
		else if (cmd == "remove") {
			cin >> num;
			auto it = find(arr.begin(), arr.end(), num);
			if (it != arr.end())
				arr.erase(it);
		}
		else if (cmd == "check") {
			cin >> num;
			auto it = find(arr.begin(), arr.end(), num);
			if (it != arr.end())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (cmd == "toggle") {
			cin >> num;
			auto it = find(arr.begin(), arr.end(), num);
			if (it != arr.end())
				arr.erase(it);
			else
				arr.push_back(num);
		}
		else if (cmd == "all") {
			arr.clear();
			for (int j = 1; j <= 20; j++) {
				arr.push_back(j);
			}
		}
		else {
			arr.clear();
		}
	}
	return 0;
}