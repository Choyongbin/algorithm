#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	vector<int> num;
	stack<vector<int>> s;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		num.push_back(a);
	}
	sort(num.begin(), num.end(), greater<int>());
	for (int i = 0; i < n; i++) {
		vector<int> temp;
		temp.push_back(num[i]);
		s.push(temp);
	}

	while (!s.empty()) {
		vector<int> temp = s.top();
		s.pop();
		if (temp.size() == m) {
			for (int i = 0; i < m; i++) {
				cout << temp[i] << " ";
			}
			cout << "\n";
		}
		else {
			for (int i = 0; i < n; i++) {
				vector<int> kk = temp;
				if (temp[temp.size() - 1] <= num[i]) {
					kk.push_back(num[i]);
					s.push(kk);
				}
			}
		}
	}
	return 0;
}