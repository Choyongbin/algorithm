#include <stdio.h>

int n, m;
int arr[100][100] = { 0 };
int visited[100][100] = { 0 };
int cnt[100][100] = { 0 };

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

struct Node {
	int x;
	int y;
};

struct Node queue[10000] = { 0 };



void bfs() {
	cnt[0][0] = 1;
	int front = 0, rear = 0, popX, popY;
	queue[0].x = 0;
	queue[0].y = 0;
	visited[0][0] = 1;
	rear++;

	while (front < rear) {
		popX = queue[front].x;
		popY = queue[front].y;
		front++;

		for (int i = 0; i < 4; i++) {
			int nx = popX + dx[i];
			int ny = popY + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m && visited[nx][ny] == 0 && arr[nx][ny] == 1) {
				cnt[nx][ny] = cnt[popX][popY] + 1;
				visited[nx][ny] = 1;
				queue[rear].x = nx;
				queue[rear].y = ny;
				rear++;
			}
		}
	}
}

int main() {
	scanf_s("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &arr[i][j]);
		}
	}
	bfs();

	printf("%d", cnt[n - 1][m - 1]);
	return 0;
}