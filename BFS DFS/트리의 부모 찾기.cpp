#include <iostream>
#include <vector>

using namespace std;
vector<int> arr[100001];
int ans[100001] = { 0 };
int visited[100001] = { 0 };

void parent(int node) {
	visited[node] = 1;
	for (int i = 0; i < arr[node].size(); i++) {
		int next = arr[node][i];
		if (visited[next] == 0) {
			ans[next] = node;
			parent(next);
		}
	}
}

int main() {
	int t, a, b;
	cin >> t;
	
	for (int i = 0; i < t-1; i++) {
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	parent(1);
	
	for (int i = 2; i <= t; i++) {
		cout << ans[i] << "\n";
	}
	
	return 0;
}