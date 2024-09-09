#include <iostream>
#include <queue>

using namespace std;

int n;
int visited[2000][2000] = { 0 };

void solve() {
	queue<pair<pair<int,int>,int>> q;
	q.push(make_pair(make_pair(1,0),0));
	visited[1][0] = 1;

	while (!q.empty()) {
		int nc = q.front().first.first;
		int flag = q.front().first.second;
		int time = q.front().second;
		q.pop();

		if (nc == n) {
			cout << time;
			return;
		}

		if (nc > 0 && nc < 2000 && visited[nc][nc] == 0) {
			visited[nc][nc] = 1;
			q.push({ { nc,nc }, time+1 });
		}

		if (flag > 0 && nc + flag < 2000 && visited[nc+flag][0] == 0) {
			visited[nc + flag][flag] = 1;
			q.push({ { nc + flag, flag }, time+1 });
		}

		if (nc > 0 && nc < 2000 && visited[nc-1][flag] == 0) {
			visited[nc - 1][flag] = 1;
			q.push({ { nc - 1, flag }, time+1 });
		}
	}
}

int main() {
	cin >> n;
	solve();

	return 0;
}