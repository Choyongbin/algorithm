#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

int N, L, R, flag = 0;
int arr[51][51];
int canMove[60][60];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void bfs(int a, int b) {
	queue<pair<int, int>> q, allQ;
	q.push({ a,b });
	allQ.push({ a,b });
	int sum = 0, cnt = 0;
	canMove[a][b] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		sum += arr[x][y];
		cnt++;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N && canMove[nx][ny] == 0 && (abs(arr[x][y] - arr[nx][ny]) >= L && abs(arr[x][y] - arr[nx][ny]) <= R)) {
				q.push({ nx,ny });
				allQ.push({ nx,ny });
				canMove[nx][ny] = 1;
			}
		}
	}

	while (!allQ.empty()) {
		int x = allQ.front().first;
		int y = allQ.front().second;
		allQ.pop();
		arr[x][y] = sum / cnt;
		if(cnt != 1)
			flag = 1;
	}
}

void checkPeople() {
	memset(canMove, 0, sizeof(canMove));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if(canMove[i][j] == 0)
				bfs(i, j);
		}
	}
}




void solve() {
	int answer = 0;
	while (1) {
		flag = 0;
		checkPeople();
		if (flag == 0)
			break;
		answer++;
	}
	cout << answer << "\n";
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	solve();
	return 0;
}