#include <iostream>
using namespace std;

char arr[21][21];
int visited[21][21];
int alp[27];

int r, c;
int answer = 1;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };


void dfs(int x, int y, int cnt) {
	if (answer < cnt)
		answer = cnt;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < r && nx >= 0 && ny < c && ny >= 0 && visited[nx][ny] == 0 && alp[arr[nx][ny] - 65] == 0) {
			alp[arr[nx][ny] - 65] = 1;
			visited[nx][ny] = 1;
			dfs(nx, ny, cnt + 1);
			visited[nx][ny] = 0;
			alp[arr[nx][ny] - 65] = 0;
		}
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}
	visited[0][0] = 1;
	alp[arr[0][0] - 65] = 1;
	dfs(0, 0, 1);
	cout << answer;
	return 0;
}