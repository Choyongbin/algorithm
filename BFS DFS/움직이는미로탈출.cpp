#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int arr[10][10] = { 0 };
int visited[10][10][10] = { 0 };

int dx[] = { 0, 0, -1, 1, 1, 1, -1, -1, 0 };
int dy[] = { 1, -1, 0, 0, 1, -1, -1, 1, 0 };

int solve() {
	queue<pair<int, pair<int, int>>> q;
	q.push({ 0,{7,0} });
	visited[0][7][0] = 1;

	while (!q.empty()) {
		int cx = q.front().second.first;
		int cy = q.front().second.second;
		int t = q.front().first;
		q.pop();

		if (cx == 0)
			return 1;

		for (int i = 0; i < 9; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (t + 1 >= 8)
				return 1;

			if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8 ) {
				continue;
			}

			if (nx - t >= 0 && arr[nx - t][ny] == '#') {
				continue;
			}

			if (nx - t - 1 >= 0 && arr[nx - t - 1][ny] == '#') {
				continue;
			}

			if (visited[t + 1][nx][ny] == 0) {
				q.push({ t + 1, {nx,ny} });
				visited[t + 1][nx][ny] = 1;
			}
		}
	}

	return 0;
}

int main() {
	string s;
	for (int i = 0; i < 8; i++) {
		cin >> s;
		for (int j = 0; j < 8; j++) {
			arr[i][j] = s[j];
		}
	}

	cout << solve();
	return 0;
}