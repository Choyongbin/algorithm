#include <iostream>
#include <string.h>

using namespace std;

#define INF 100000000

int map[501][501];

int main() {
	int n, m, a, b;
	int answer = 0;
	scanf_s("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		scanf_s("%d%d", &a, &b);
		map[a][b] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (map[j][k] > map[j][i] + map[i][k])
					map[j][k] = map[j][i] + map[i][k];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int count = 0;
		for (int j = 1; j <= n; j++) {
			if (map[i][j] != INF || map[j][i] != INF) {
				count++;
			}
		}
		if (count == n - 1) answer++;
	}
	printf("%d\n", answer);
	return 0;
}