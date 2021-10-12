#include <vector>
#include <iostream>
#include <queue>

using namespace std;
#define MAX 100

int box[MAX][MAX];
int visited[MAX][MAX];  // 1 : outair, -1 : cheese, 0 : inair
vector<pair<int, int>> cheese;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int N, M, temp;


void bfs() {
	queue<pair<int,int>> q;
	q.push(make_pair(0, 0));
	visited[0][0] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int tempX = x + dx[i];
			int tempY = y + dy[i];

			if (tempX >= 0 && tempY >= 0 && tempX < N && tempY < M && visited[tempX][tempY] == 0 ) {
				visited[tempX][tempY] = 1;
				q.push(make_pair(tempX, tempY));
			}
		}
	}
}

void getcheese() {
	vector<int> temp;
	for (int i = 0; i < cheese.size(); i++) {
		int x = cheese[i].first;
		int y = cheese[i].second;
		int count = 0;

		for (int i = 0; i < 4; i++) {
			int tempX = x + dx[i];
			int tempY = y + dy[i];

			if (tempX >= 0 && tempY >= 0 &&  tempX < N && tempY < M && visited[tempX][tempY] == 1 && box[tempX][tempY] == 0)
				count++;
		}

		if (count >= 2) {
			box[x][y] = 0;
			temp.push_back(i);
		}
	}
	for (int i = 0; i < temp.size(); i++) {
		cheese.erase(cheese.begin() + temp[i]);
		for (int j = i; j < temp.size(); j++) {
			temp[j]--;
		}
	}
	
}



void solve() {
	int count = 0;
	while (1) {
		if (cheese.size() == 0)
			break;
		count++;

		bfs();
		getcheese();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				visited[i][j] = 0;
			}
		}

		for (int i = 0; i < cheese.size(); i++) {
			visited[cheese[i].first][cheese[i].second] = -1;
		}
	}
	cout << count;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> temp;
			box[i][j] = temp;
			if (temp == 1) {
				visited[i][j] = -1;
				cheese.push_back(make_pair(i, j));
			}
		}
	}
	
	solve();
}