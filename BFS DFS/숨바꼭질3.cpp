#include <iostream>
#include <queue>

using namespace std;

int visited[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	int minnum = 987654321;
	queue<pair<int, int>> q;
	cin >> n >> k;
	visited[n] = 1;
	q.push({ n,0 });

	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		visited[x] = 1;
		q.pop();

		if (x == k && minnum > cnt) {
			minnum = cnt;
			continue;
		}

		if (cnt > minnum)
			continue;

		if (x + 1 <= 100000 && visited[x + 1] != 1) {
			q.push({ x + 1, cnt + 1 });
		}
		if (x - 1 >= 0 && visited[x - 1] != 1) {
			q.push({ x - 1,cnt + 1 });
		}
		if (x * 2 <= 100000 && visited[x * 2] != 1) {
			q.push({ 2 * x, cnt });
		}
	}

	cout << minnum;
	return 0;
}