#include <iostream>
#include <queue>

using namespace std;

int arr[1003][1003];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int m, n, answer = -100;
	queue<pair<int, int>> q;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				q.push({ i,j });
			}
		}
	}
	if (q.size() == m * n) {
		cout << "0\n";
		return 0;
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] == 0) {
				arr[nx][ny] = arr[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				cout << "-1\n";
				return 0;
			}
			if (arr[i][j] > answer) {
				answer = arr[i][j];
			}
		}
	}
	cout << answer-1 << "\n";
	
	return 0;
}