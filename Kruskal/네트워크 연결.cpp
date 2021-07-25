#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int parent[100001];

vector<pair<int, pair<int, int>>> v;

int find(int num) {
	if (parent[num] == num) return num;
	else
		return parent[num] = find(parent[num]);
}

void union_set(int x, int y) {
	int xp = find(x);
	int yp = find(y);
	if (xp != yp) parent[xp] = yp;
}

int solution(int x, int y) {
	int xp = find(x);
	int yp = find(y);

	if (xp == yp) return 1;
	else return 0;
}


int main() {
	int n, m, a, b, c, answer;
	answer = 0;
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v.push_back(make_pair(c, make_pair(a, b)));	
	}
	sort(v.begin(), v.end());
	for (int i = 0; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m; i++) {
		if (solution(v[i].second.first, v[i].second.second) == 0) {
			union_set(v[i].second.first, v[i].second.second);
			answer += v[i].first;
		}
	}
	cout << answer << endl;	
	
}