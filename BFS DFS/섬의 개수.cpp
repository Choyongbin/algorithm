#include <iostream>
#include <vector>

using namespace std;

int answer = 0;
int w, h;
int arr[51][51];
int visited[51][51];

int dx[] = { 0,0,1,-1, 1, -1,1,-1 };
int dy[] = { 1,-1,0,0, -1, 1,1,-1 };

void dfs(int x, int y) {
	visited[x][y] = 1;

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < h && ny >= 0 && ny < w && visited[nx][ny] == 0 && arr[nx][ny] == 1) {
			dfs(nx, ny);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (1) {
		vector<pair<int, int>> start;
		cin >> w >> h;
		for (int i = 0; i < 51; i++) {
			for (int j = 0; j < 51; j++) {
				arr[i][j] = 0;
				visited[i][j] = 0;
				answer = 0;
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 1) {
					start.push_back({ i,j });
				}
			}
		}
		if (w == 0 && h == 0)
			break;
		for (int i = 0; i < start.size(); i++) {
			if (visited[start[i].first][start[i].second] == 0) {
				dfs(start[i].first, start[i].second);
				answer++;
			}
		}
		cout << answer << "\n";
	}
	return 0;
}