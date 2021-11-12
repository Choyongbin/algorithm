#include <iostream>
#include <vector>

using namespace std;
int n, m, a, b;
vector<int> arr[1001];
int visited[1001] = { 0 };

void dfs(int start) {
	visited[start] = 1;
	for (int i = 0; i < arr[start].size(); i++) {
		if (visited[arr[start][i]] == 0) {
			visited[arr[start][i]] = 1;
			dfs(arr[start][i]);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			ans++;
			dfs(i);
		}
	}
	cout << ans;
	return 0;
}