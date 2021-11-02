#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

vector<pair<int, int>> dist[1001];
int d[1001] = { 0 };
int res[1001] = { 0 };

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(start, 0));

	while (!pq.empty()) {
		int current = pq.top().first;
		int distance = -pq.top().second;
		pq.pop();

		if (d[current] < distance)
			continue;
		for (int i = 0; i < dist[current].size(); i++) {
			int next = dist[current][i].first;
			int cost = dist[current][i].second + distance;
			if (cost < d[next]) {
				d[next] = cost;
				pq.push(make_pair(next, -cost));
			}
		}
	}
}

int main() {
	int n, x, m;
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		int start, end, time;
		cin >> start >> end >> time;
		dist[start].push_back(make_pair(end, time));
	}
	for (int j = 1; j < n+1; j++) {
		for (int i = 1; i < n+1; i++) {
			d[i] = INF;
		}
		dijkstra(j);
		res[j] = d[x];
	}
	for (int j = 1; j < n+1; j++)
		d[j] = INF;
	dijkstra(x);
	for (int j = 1; j < n+1; j++)
		res[j] = res[j] + d[j];
	sort(res+1, res + n+1);
	for (int i = 1; i < n+1; i++) {
		cout << res[i] << " ";
	}

	cout << res[n];

	
	return 0;
}