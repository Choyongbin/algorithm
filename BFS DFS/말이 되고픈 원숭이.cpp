#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[12] = { 1,0,-1,0,2,2,1,1,-1,-1,-2,-2 };
int dy[12] = { 0,1,0,-1,-1,1,-2,2,-2,2,-1,1 };

int arr[201][201];
int dist[201][201][31];

struct node {
	int x, y, z;
};

queue<node> q;

int w, h, k;

int bfs() {
	q.push({ 0,0,0 });
	dist[0][0][0] = 0;

	while (!q.empty()) {
		node cur = q.front();
		int x = cur.x;
		int y = cur.y;
		int z = cur.z;

		if (x == h - 1 && y == w - 1)
			return dist[x][y][z];
		q.pop();

		for (int i = 0; i < 12; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z;

			if (nx < 0 || nx >= h || ny < 0 || ny >= w || dist[nx][ny][nz] || arr[nx][ny] == 1)
				continue;
			if (i >= 4) {
				if (nz >= k || dist[nx][ny][nz + 1])
					continue;
				dist[nx][ny][nz + 1] = dist[x][y][z] + 1;
				q.push({ nx,ny,nz + 1 });
			}
			else {
				dist[nx][ny][nz] = dist[x][y][z] + 1;
				q.push({ nx,ny,nz });
			}
		}
	}
	return -1;
}

int main() {
	cin >> k >> w >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arr[i][j];
		}
	}

	cout << bfs();
	return 0;
}