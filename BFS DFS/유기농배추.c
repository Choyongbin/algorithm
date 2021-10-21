#include <stdio.h>

int m, n, k;
int arr[51][51] = { 0 };
int visited[51][51] = { 0 };
int answer = 0;

int dx[] = { 1, -1, 0 ,0 };
int dy[] = { 0, 0, 1, -1 };

struct Node {
	int x;
	int y;
};

void bfs(int startX, int startY) {
	if (visited[startX][startY] == 1 || arr[startX][startY] == 0)
		return;
	int front = 0, rear = 0, popX, popY;
	visited[startX][startY] = 1;
	struct Node queue[2501] = { 0 };
	queue[0].x = startX;
	queue[0].y = startY;
	rear++;
	answer++;

	while (front < rear) {
		popX = queue[front].x;
		popY = queue[front].y;
		front++;
		for (int i = 0; i < 4; i++) {
			int nx = popX + dx[i];
			int ny = popY + dy[i];
			if (nx >= 0 && ny >= 0 && nx < m && ny < n && visited[nx][ny] == 0 && arr[nx][ny] == 1) {
				queue[rear].x = nx;
				queue[rear].y = ny;
				visited[nx][ny] = 1;
				rear++;

			}
		}
	}
	
}

int main() {
	int t;
	scanf_s("%d", &t);

	for (int i = 0; i < t; i++) {
		int x, y;
		answer = 0;
		for (int a = 0; a < 50; a++) {
			for (int b = 0; b < 50; b++) {
				arr[a][b] = 0;
			}
		}
		scanf_s("%d %d %d", &m, &n, &k);
		for (int j = 0; j < k; j++) {
			scanf_s("%d %d", &x, &y);
			arr[x][y] = 1;
		}
		for (int a = 0; a < m; a++) {
			for (int b = 0; b < n; b++) {
				visited[a][b] = 0;
			}
		}

		for (int a = 0; a < m; a++) {
			for (int b = 0; b < n; b++) {
				bfs(a, b);
			}
		}
		printf("%d\n", answer);
	}
	
	return 0;
}