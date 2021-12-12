#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v[501];
int visited[501];
bool cycle = 0;
/*
void dfs(int start) {
	visited[start] = 1;
	for (int j = 0; j < v[start].size(); j++) {
		if (visited[v[start][j]] == 0) {
			dfs(v[start][j]);
		}
		else {
			//cout << v[start][j] + 1 << "\n";
			cycle = 1;
			return;
		}
	}
}*/

bool dfs(int x, int post_x){
	visited[x] = 1;

	for (int i = 0; i < v[x].size(); i++)
	{
		if (v[x][i] == post_x) 
			continue;
		if (visited[v[x][i]])
			return false;
		if (dfs(v[x][i], x) == false) 
			return false;
	}
	return true;
}

int main() {
	int cnt = 1;
	while (1) {
		for (int i = 1; i <= 500; i++) {
			visited[i] = 0;
			v[i].clear();
		}
		int answer = 0;
		cycle = 0;
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for (int i = 1; i <= n; i++) {
			if (visited[i] == 0) {
				if(dfs(i,0))
					answer++;
			}
		}
		if (answer == 0)
			cout << "Case " << cnt << ": No trees." << "\n";
		else if (answer == 1)
			cout << "Case " << cnt << ": There is one tree.\n";
		else if (answer > 1)
			cout << "Case " << cnt << ": A forest of "<< answer << " trees.\n";
		cnt++;
	}
	return 0;
}