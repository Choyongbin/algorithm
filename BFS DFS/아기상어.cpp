#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int arr[20][20];
int n;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int babySize = 2;
int currentEat = 0;

bool cmp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b) {
	if (a.second == b.second) {
		if (a.first.first == b.first.first)
			return a.first.second < b.first.second;
		else
			return a.first.first < b.first.first;
	}
	return a.second < b.second;
}

pair<pair<int,int>,int> bfs(int x, int y) {
	int visited[20][20] = { 0 };
	visited[x][y] = 1;
	queue<pair<pair<int, int>,int>> q;
	vector<pair<pair<int, int>,int>> v;
	q.push({ { x,y },0 });

	while (!q.empty()) {
		int a = q.front().first.first;
		int b = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < n && visited[nx][ny] == 0 && arr[nx][ny] <= babySize) {
				if (arr[nx][ny] < babySize && arr[nx][ny] != 0)
					v.push_back({ { nx,ny },cnt + 1 });
				visited[nx][ny] = 1;
				q.push({ {nx,ny},cnt + 1 });
			}
		}
	}
	if (v.size() == 0)
		return make_pair(make_pair(-1,-1),-1);
	sort(v.begin(), v.end(), cmp);
	return v[0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int startX = 0, startY = 0, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				startX = i;
				startY = j;
				arr[i][j] = 0;
			}
		}	
	}
	while (true) {
		pair<pair<int,int>,int> temp = bfs(startX, startY);
		if (temp.first.first == -1 && temp.first.second == -1 && temp.second == -1)
			break;
		startX = temp.first.first;
		startY = temp.first.second;
		arr[startX][startY] = 0;
		currentEat++;
		sum += temp.second;
		if (currentEat == babySize) {
			currentEat = 0;
			babySize++;
		}
	}

	cout << sum;
	return 0;
}