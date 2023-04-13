#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int arr[301][301] = { 0 };
int visited[301][301] = { 0 };
int temp[301][301] = { 0 };
int n, m;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void check(int x, int y) {
	queue<pair<int, int>> q;
	q.push({x, y});

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if (arr[nx][ny] != 0 && visited[nx][ny] == 0) {
				q.push({ nx,ny });
				visited[nx][ny] = 1;
			}
		}
	}
}

void melt() {
	memset(temp, 0, sizeof(temp));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0)
				continue;

			int meltcount = 0;
			
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m)
					continue;

				if (arr[nx][ny] == 0)
					meltcount++;
			}
			temp[i][j] = arr[i][j] - meltcount;
			if (temp[i][j] < 0)
				temp[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = temp[i][j];
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int time = 0;
	while (true) {
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visited[i][j] == 0 && arr[i][j] != 0) {
					check(i, j);
					cnt++;
				}

			}
		}

		if (cnt == 0) {
			cout << 0;
			return 0;
		}
		else if (cnt >= 2) {
			cout << time;
			return 0;
		}

		time++;
		melt();
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}