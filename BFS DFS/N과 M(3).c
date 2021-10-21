#include <stdio.h>
int n, m;
int arr[10];

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
			arr[num] = i;
			dfs(num + 1);
		}
	}
}

int main() {
	scanf_s("%d %d", &n, &m);
	dfs(0);
	return 0;
}