#include <iostream>
#include <queue>
using namespace std;
int visited[100001] = { 0 };
int n, k;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	queue<pair<int,int>> q;
	visited[n] = 1;
	q.push(make_pair(n,0));
	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (x == k) {
			cout << cnt;
			return 0;
		}
		if (x + 1 >= 0 && x+1 <=100000 && visited[x+1] == 0) {
			visited[x + 1] = 1;
			q.push(make_pair(x + 1,cnt+1));
		}
		if (x - 1 >= 0 && x - 1 <= 100000 && visited[x - 1] == 0) {
			visited[x - 1] = 1;
			q.push(make_pair(x - 1, cnt + 1));
		}
		if (x * 2 >= 0 && x * 2 <= 100000 && visited[x * 2] == 0) {
			visited[2 * x] = 1;
			q.push(make_pair(x * 2, cnt + 1));
		}
	}
	return 0;
}