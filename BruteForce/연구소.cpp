#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int tempArr[9][9];
int arr[9][9];
int virus[9][9];
int ans = 0;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void copyArr() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tempArr[i][j] = arr[i][j];
		}
	}
}

void copyVirus() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			virus[i][j] = tempArr[i][j];
		}
	}
}

int countVirus() {
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (virus[i][j] == 0) {
				count++;
			}
		}
	}
	return count;
}

void bfs() {
	copyVirus();
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (virus[i][j] == 2) {
				q.push(make_pair(i, j));
			}
		}
	}	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && virus[nx][ny] == 0) {
				virus[nx][ny] = 2;
				q.push(make_pair(nx, ny));
			}
		}
	}
	int count = countVirus();
	ans = max(ans, count);
}

void makeWall(int cnt) {
	if (cnt == 3) {
		bfs();
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tempArr[i][j] == 0) {
				tempArr[i][j] = 1;
				makeWall(cnt + 1);
				tempArr[i][j] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				copyArr();
				tempArr[i][j] = 1;
				makeWall(1);
				tempArr[i][j] = 0;
			}
		}
	}
	cout << ans;
	return 0;
}