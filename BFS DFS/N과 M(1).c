#include <stdio.h>

int n, m;
int arr[10] = { 0 };
int isused[10] = { 0 };

void dfs(int num) {
	if (num == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (isused[i] == 0) {
				isused[i] = 1;
				arr[num] = i;
				dfs(num + 1);
				isused[i] = 0;
			}
		}
	}
}

int main() {
	scanf_s("%d %d", &n, &m);
	dfs(0);
	return 0;
}