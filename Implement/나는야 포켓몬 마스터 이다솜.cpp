#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	unordered_map<string, int> map1;
	unordered_map<int, string> map2;
	string cmd;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		map1.insert(make_pair(a, i+1));
		map2.insert(make_pair(i, a));
	}
	for (int i = 0; i < m; i++) {
		cin >> cmd;
		if (isdigit(cmd[0]) == 0) {
			cout << map1[cmd] << "\n";
		}
		else {
			cout << map2[stoi(cmd)-1] << "\n";
		}
	}
	return 0;
}