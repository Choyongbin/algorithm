#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int arr[1500][1500] = { 0 };  // 0: 물, 1:백조, -1 : 얼음
int visited[1500][1500] = { 0 };
int r, c;

//vector<pair<pair<int, int>, bool>> ice; //얼음 위치
queue<pair<int, int>> swanQ, tempswanQ; //백조 위치
queue<pair<int, int>> waterQ, tempwaterQ;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

bool meet = 0;
/*
void melting() {
	vector<pair<int,int>> temp;
	for (int i = 0; i < ice.size(); i++) {
		if (ice[i].second == false) {
			for (int j = 0; j < 4; j++) {
				int nx = ice[i].first.first + dx[j];
				int ny = ice[i].first.second + dy[j];
				if (nx >= 0 && nx < r && ny >= 0 && ny < c && arr[nx][ny] == 0) {
					temp.push_back({ ice[i].first.first,ice[i].first.second });
					ice[i].second = true;
					break;
				}
			}
		}
	}
	for (int i = 0; i < temp.size(); i++) {
		arr[temp[i].first][temp[i].second] = 0;
	}
}
*/

void melting() {
	while (!waterQ.empty()) {
		int tempX = waterQ.front().first;
		int tempY = waterQ.front().second;
		waterQ.pop();
		for (int i = 0; i < 4; i++) {
			int nx = tempX + dx[i];
			int ny = tempY + dy[i];
			if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
				if (arr[nx][ny] == -1) {
					arr[nx][ny] = 0;
					tempwaterQ.push({ nx,ny });
				}
			}
		}
	}
}

void meetSwan() {
	while (!swanQ.empty()) {
		int tempX = swanQ.front().first;
		int tempY = swanQ.front().second;
		swanQ.pop();
		for (int i = 0; i < 4; i++) {
			int nx = tempX + dx[i];
			int ny = tempY + dy[i];
			if (nx >= 0 && nx < r && ny >= 0 && ny < c && visited[nx][ny] == 0) {
				if (arr[nx][ny] == 1) {
					meet = 1;
					return;
				}
				else if (arr[nx][ny] == -1) {
					tempswanQ.push({ nx, ny });
				}
				else {
					swanQ.push({ nx, ny });
				}
				visited[nx][ny] = 1;
			}
		}
	}
}

void solve() {
	int count = 0;
	while (meet == 0) {
		meetSwan();
		if (meet == 1)
			break;
		melting();
		queue<pair<int, int>> empty1;
		queue<pair<int, int>> empty2;
		swanQ = tempswanQ;
		waterQ = tempwaterQ;
		swap(tempswanQ, empty1);
		swap(tempwaterQ, empty2);
		count++;
	}
	cout << count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < c; j++) {
			if (temp[j] == '.') { //물
				arr[i][j] = 0;
				waterQ.push({ i,j });
			}
			else if (temp[j] == 'X') { //얼음
				arr[i][j] = -1;
				//ice.push_back(make_pair(make_pair(i, j), false));
			}
			else { //백조
				arr[i][j] = 1;
				if (swanQ.size() == 0) {
					swanQ.push({ i,j });
					visited[i][j] = 1;
				}
					
			}
		}
	}
	
	solve();
	return 0;
}