#include <iostream>
#include <string>
#include <vector>

using namespace std;

int value[101][100001] = { 0 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	vector<pair<int, int>> thing;
	thing.push_back(make_pair(0, 0));
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		int w, v;
		cin >> w >> v;
		thing.push_back(make_pair(w, v));
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			int tempW = thing[i].first;
			int tempV = thing[i].second;
			if (tempW > j)
				value[i][j] = value[i-1][j];
			else
				value[i][j] = max(value[i-1][j], value[i-1][j - tempW] + tempV);
		}
	}
	cout << value[N][K];

	return 0;


}