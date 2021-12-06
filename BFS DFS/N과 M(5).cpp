#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	stack < pair<vector<int>, vector<int>>> s;
	vector<int> aa;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		aa.push_back(a);
	}
	sort(aa.begin(), aa.end(), greater<int>());
	for (int i = 0; i < n; i++) {
		vector<int> num;
		vector<int> num1;
		num.push_back(aa[i]);
		num1.push_back(i);
		s.push({ num,num1 });
	}

	while (!s.empty()) {
		vector<int> temp = s.top().first;
		vector<int> visited = s.top().second;
		s.pop();
		if (temp.size() == m) {
			for (int i = 0; i < m; i++) {
				cout << temp[i] << " ";
			}
			cout << "\n";
		}
		else {
			for (int i = 0; i < n; i++) {
				auto it = find(visited.begin(), visited.end(), i);
				if (it == visited.end()) {
					temp.push_back(aa[i]);
					visited.push_back(i);
					s.push({ temp,visited });
					auto li = temp.end();
					auto li2 = visited.end();
					li--;
					li2--;
					temp.erase(li);
					visited.erase(li2);
				}
			}
		}
	}
	return 0;
}