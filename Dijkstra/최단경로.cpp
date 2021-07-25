#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr auto INF = 1000000000;
vector<pair<int, int>> gp[20001];
priority_queue<pair<int, int>> pq;
int d[20001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int v, e, u, w, V, k;
	/*
	cin >> V >> e;
	cin >> k;
	*/
	scanf("%d%d", &V, &e);
	scanf("%d", &k);

	for (int i = 0; i < e; i++) {
		//cin >> u >> v >> w;
		scanf("%d%d%d", &u, &v, &w);
		gp[u].push_back(make_pair(v, w));
	}
	for (int i = 1; i <= V; i++) d[i] = INF;

	pq.push(make_pair(0, k));
	d[k] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;

		pq.pop();

		for (int i = 0; i < gp[cur].size(); i++) {
			int next = gp[cur][i].first;
			int toCost = gp[cur][i].second;

			if (d[next] > d[cur] + toCost) {
				d[next] = d[cur] + toCost;
				pq.push(make_pair(-d[next], next));	
			}
		}
	}
	
	for (int i = 1; i <= V; i++) {
		if (d[i] == INF) printf("INF\n");
		else printf("%d\n", d[i]);
	}
	
	return 0;
}