#include <stdio.h>

int visited[26][26] = { 0 };
int arr[26][26] = { 0 };
int ans[1000] = { 0 };

int dx[] = { 1, 0, 0, -1 };
int dy[] = { 0, -1, 1, 0 };

int n, answer=0, count = 0;

struct Node {
	int x;
	int y;
};

void bfs(int startX, int startY) {
	if (visited[startX][startY] == 1 || arr[startX][startY] == 0)
		return;
	answer++;
	count++;
	ans[count]++;
	struct Node queue[1000] = { 0, };
	visited[startX][startY] = 1;
	int front = 0, rear = 0, popX, popY;
	queue[0].x = startX;
	queue[0].y = startY;
	rear++;

	while (front < rear) {
		popX = queue[front].x;
		popY = queue[front].y;
		front++;
		for (int i = 0; i < 4; i++) {
			int nx = popX + dx[i];
			int ny = popY + dy[i];
			if (nx >= 1 && ny >= 1 && nx<=n && ny <=n && arr[nx][ny] == 1 && visited[nx][ny] == 0) {
				ans[count]++;
				visited[nx][ny] = 1;
				queue[rear].x = nx;
				queue[rear].y = ny;
				rear++;
			}

		}
	}
}

int main() {
	int temp = 0;
	scanf_s("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf_s("%1d", &arr[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			bfs(i, j);
		}
	}
	for (int i = 1; i <= answer; i++) {
		for (int j = 1; j < answer; j++) {
			if (ans[j] > ans[j + 1]) {
				temp = ans[j];
				ans[j] = ans[j + 1];
				ans[j + 1] = temp;
			} 
		}
	}
	printf("%d\n", answer);
	for (int i = 1; i <= answer; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}