#include <iostream>
#include <queue>

using namespace std;

int arr[1001][1001] = { 0 };
int visited[1001][1001][2] = { 0 };

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int n, m;
void bfs() {
	queue<pair<pair<int,int>,int>> q;
	q.push(make_pair(make_pair(0, 0), 1));
	visited[0][0][1] = 1;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int block = q.front().second;
		q.pop();
		//cout << x << " " << y << " " << block << "\n";

		if (x == n - 1 && y == m - 1) {
			cout << visited[x][y][block] << "\n";
			return;
		}
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				cout << nx << " " << ny << "\n";
				if (arr[nx][ny] == 1 && block == 1) {
					visited[nx][ny][block-1] = visited[x][y][block] + 1;
					q.push(make_pair(make_pair(nx, ny), block-1));
				}
				else if (arr[nx][ny] == 0 && visited[nx][ny][block] == 0) {
					visited[nx][ny][block] = visited[x][y][block] + 1;
					q.push(make_pair(make_pair(nx, ny), block));
				}
				
			}
		}
	}
	cout << -1;
	return;
}


int main() {
	string temp;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		for (int j = 0; j < m; j++) {
			arr[i][j] = temp[j] - '0';
		}
	}
	bfs();
	return 0;
}