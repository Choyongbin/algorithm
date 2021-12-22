#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int visited[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	int minnum = 987654321;
	queue<pair<int, int>> q;
	vector<int> answer;
	cin >> n >> k;
	q.push(make_pair(n, 0));


	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		visited[x] = 1;
		q.pop();


		if (x == k && minnum > cnt) {
			minnum = cnt;
			answer = temp;
			continue;
		}

		if (cnt > minnum)
			continue;

		if (x + 1 <= 100000 && visited[x + 1] != 1) {
			temp.push_back(x + 1);
			q.push({ { x + 1, cnt + 1 }, temp });
			auto aa = temp.end();
			aa--;
			temp.erase(aa);
		}
		if (x - 1 >= 0 && visited[x - 1] != 1) {
			temp.push_back(x - 1);
			q.push({ { x - 1,cnt + 1 }, temp });
			auto aa = temp.end();
			aa--;
			temp.erase(aa);
		}
		if (x * 2 <= 100000 && visited[x * 2] != 1) {
			temp.push_back(x * 2);
			q.push({ { 2 * x, cnt + 1 },temp });
			auto aa = temp.end();
			aa--;
			temp.erase(aa);
		}
	}

	cout << minnum << "\n";
	for (auto it : answer) {
		cout << it << " ";
	}

	return 0;
}

/*
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	int minnum = 987654321;
	queue<pair<pair<int, int>, vector<int>>> q;
	vector<int> path;
	vector<int> answer;
	cin >> n >> k;
	path.push_back(n);
	q.push(make_pair(make_pair(n,0), path));


	while (!q.empty()) {
		int x = q.front().first.first;
		int cnt = q.front().first.second;
		vector<int> temp = q.front().second;
		visited[x] = 1;
		q.pop();


		if (x == k && minnum > cnt) {
			minnum = cnt;
			answer = temp;
			continue;
		}

		if (cnt > minnum)
			continue;

		if (x + 1 <= 100000 && visited[x + 1] != 1) {
			temp.push_back(x + 1);
			q.push({ { x + 1, cnt + 1 }, temp });
			auto aa = temp.end();
			aa--;
			temp.erase(aa);
		}
		if (x - 1 >= 0 && visited[x - 1] != 1) {
			temp.push_back(x - 1);
			q.push({ { x - 1,cnt + 1 }, temp });
			auto aa = temp.end();
			aa--;
			temp.erase(aa);
		}
		if (x * 2 <= 100000 && visited[x * 2] != 1) {
			temp.push_back(x * 2);
			q.push({ { 2 * x, cnt + 1 },temp });
			auto aa = temp.end();
			aa--;
			temp.erase(aa);
		}
	}

	cout << minnum << "\n";
	for (auto it : answer) {
		cout << it << " ";
	}

	return 0;
}
*/