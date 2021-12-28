#include <iostream>

using namespace std;

char map1[100][100];
char map2[100][100];

int n;
int visited1[100][100];
int visited2[100][100];

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void dfs1(int x, int y, char cur) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < n && ny >= 0 && ny < n && visited1[nx][ny] == 0 && cur == map1[nx][ny]) {
			visited1[nx][ny] = 1;
			dfs1(nx, ny, cur);
		}
	}
}

void dfs2(int x, int y, char cur) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < n && ny >= 0 && ny < n && visited2[nx][ny] == 0 && cur == map2[nx][ny]) {
			visited2[nx][ny] = 1;
			dfs2(nx, ny, cur);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int ans1 = 0, ans2 = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < n; j++) {
			map1[i][j] = a[j];
			if (a[j] == 'R')
				map2[i][j] = 'G';
			else
				map2[i][j] = a[j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited1[i][j] == 0) {
				ans1++;
				dfs1(i, j, map1[i][j]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited2[i][j] == 0) {
				ans2++;
				dfs2(i, j, map2[i][j]);
			}
		}
	}

	cout << ans1 << " " << ans2;


	return 0;
}