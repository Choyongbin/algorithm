//#include <stdio.h>
//
//int n, count =0;
//int arr[15][15] = { 0 };
//
//int dx[] = { 0, 1, -1, 0 };
//int dy[] = { 1, 0, 0, -1 };
//
//int isokay(int x, int y) {
//	for (int i = 0; i < x; i++) {
//		if (arr[i][y] == 1)
//			return 0;
//	}
//	for (int i = 0; i < y; i++) {
//		if (arr[x][i] == 1)
//			return 0;
//	}
//	if (x > y) {
//		for (int i = 1; i <= y; i++) {
//			if (arr[x - i][y - i] == 1)
//				return 0;
//		}
//	}
//	else {
//		for (int i = 1; i <= x; i++) {
//			if (arr[x - i][y - i] == 1)
//				return 0;
//		}
//	}
//	return 1;
//
//}
//
//void dfs(int x, int y) {
//	if (x == n - 1 && y == n - 1) {
//		count++;
//		return;
//	}
//	for (int i = 0; i < 4; i++) {
//		int nx = x + dx[i];
//		int ny = y + dy[i];
//
//		if (nx < n && ny < n && nx>=0 && ny>=0 && isokay(nx, ny)==1) {
//			arr[nx][ny] = 1;
//			dfs(nx, ny);
//			arr[nx][ny] = 0;
//		}
//	}
//}
//
//int main() {
//	scanf_s("%d", &n);
//
//	dfs(0, 0);
//
//	printf("%d", count);
//
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
int n;
int count = 0;
int arr[15] = { 0 };

int isokay(int num) {
	for (int i = 0; i < num; i++) {
		if (arr[num] == arr[i] || num - i == abs(arr[num] - arr[i]))
			return 0;
	}
	return 1;
}

void dfs(int num) {
	if (num == n) {
		count++;
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			arr[num] = i;
			if (isokay(num)) {
				dfs(num + 1);
			}
		}
	}
}

int main() {
	scanf_s("%d", &n);
	dfs(0);
	printf("%d", count);
	return 0;
}