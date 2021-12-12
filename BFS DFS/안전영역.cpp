#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[102][102];
int visited[102][102];
int temp[102][102];
int answer = 0;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void dfs(int x, int y) {
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < n && ny >= 0 && ny < n && visited[nx][ny] == 0 && temp[nx][ny] > 0)
			dfs(nx, ny);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int rain = 1;
	int maxHight = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > maxHight)
				maxHight = arr[i][j];
		}
	}
	while (rain < maxHight) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				visited[i][j] = 0;
			}
		}
		vector<pair<int, int>> start;
		int tempAns = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				temp[i][j] = arr[i][j] - rain;
				if (temp[i][j] > 0)
					start.push_back({ i,j });
			}
		}
		for (int i = 0; i < start.size(); i++) {
			if (visited[start[i].first][start[i].second] == 0) {
				dfs(start[i].first, start[i].second);
				tempAns++;
			}
		}
		if (answer < tempAns)
			answer = tempAns;
		rain++;
	}
	if (answer == 0)
		answer = 1;
	cout << answer;
	
	
	return 0;
}