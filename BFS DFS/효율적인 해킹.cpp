#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, cnt, nMax;
vector<int> arr[100000];
int visited[100000];
vector<int> ans;

void dfs(int k) {
	visited[k] = 1;
	cnt++;
	for (auto i : arr[k]) {
		if (visited[i] == 0)
			dfs(i);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		cnt = 0;
		for (int j = 1; j <= n; j++) {
			visited[j] = 0;
		}

		dfs(i);
		if (cnt > nMax) {
			ans.clear();
			ans.push_back(i);
			nMax = cnt;
		}
		else if (cnt == nMax) {
			ans.push_back(i);
		}
	}

	for (auto w : ans) {
		cout << w << " ";
	}
	return 0;
}