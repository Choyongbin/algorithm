#include <iostream>
#include <queue>

using namespace std;

int dx[] = { -1,1 };
int visited[100001] = { 0 };

int main() {
	int n, k;
	int minNum = 987654321;
	int answer = 0;
	cin >> n >> k;
	queue<pair<int,int>> q;
	q.push({ n,0 });
	visited[n] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		visited[x] = 1;

		if (cnt > minNum)
			continue;

		if (x == k) {
			if (minNum > cnt) {
				answer = 1;
				minNum = cnt;
			}
			else if (minNum == cnt) {
				answer++;
			}
			continue;
		}

		for (int i = 0; i < 2; i++) {
			int nx = x + dx[i];
			if (nx >= 0 && nx <= 100000 && visited[nx] != 1) {
				q.push({ nx,cnt + 1 });
			}
		}

		int nx = 2 * x;
		if (nx >= 0 && nx <= 100000 && visited[nx] != 1) {
			q.push({ nx,cnt + 1 });
		}
	}

	cout << minNum << "\n" << answer;
	return 0;
}