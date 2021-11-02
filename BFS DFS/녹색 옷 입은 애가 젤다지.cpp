#include <iostream>
#include <queue>
#define INF 987654321

using namespace std;
int n;
int t = 1;
int dx[] = { 1,0,0,-1 };
int dy[] = { 0,1,-1,0 };
int arr[125][125] = { 0 };
int visited[125][125] = { 0 };

void bfs() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = INF;
		}
	}
	visited[0][0] = arr[0][0];
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, 0));
	while (!pq.empty()) {
		int x = pq.top().first;
		int y = pq.top().second;
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny<n && visited[nx][ny] > visited[x][y] + arr[nx][ny]) {
				visited[nx][ny] = visited[x][y] + arr[nx][ny];
				pq.push(make_pair(nx, ny));
			}
		}
	}
	cout << "Problem " << t++<<": "<<visited[n - 1][n - 1] << "\n";
}

int main() {
	while (true) {
		cin >> n;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		bfs();
	}
	return 0;
}