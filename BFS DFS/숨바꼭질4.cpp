#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int visited[100001];
int path[100001];

int main() {
	int n, k;
	cin >> n >> k;
	queue<pair<int,int>> q;
	vector<int> ans;
	q.push({ n,0 });
	visited[n] = 1;
	
	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (x == k) {
			cout << cnt << "\n";
			int idx = x;
			while (idx != n) {
				ans.push_back(idx);
				idx = path[idx];
			}
			ans.push_back(n);
			break;
		}

		if (x - 1 >= 0 && visited[x - 1] == 0) {
			q.push({ x - 1,cnt + 1 });
			path[x - 1] = x;
			visited[x - 1] = 1;
		}

		if (x + 1 <= 100000 && visited[x + 1] == 0) {
			q.push({ x + 1, cnt + 1 });
			path[x + 1] = x;
			visited[x + 1] = 1;
		}

		if (2 * x <= 100000 && visited[2 * x] == 0) {
			q.push({ 2 * x, cnt + 1 });
			path[2 * x] = x;
			visited[x * 2] = 1;
		}

	}

	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << " ";
	}
	return 0;
}