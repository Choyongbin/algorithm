#include <iostream>

using namespace std;

int arr[51][51];
int after[51][51];
int n, m, r, c, d, flag;
int answer = 0;

int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };

int main() {
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	while (1) {
		if (!after[r][c]) {
			answer++;
		}
		after[r][c] = 1;
		flag = 1;
		for (int i = 1; i <= 4; i++) {
			int nd = (4 + d - i) % 4;
			int nr = r + dr[nd];
			int nc = c + dc[nd];

			if(after[nr][nc] || arr[nr][nc])
				continue;
			flag = 0;
			r = nr;
			c = nc;
			d = nd;
			break;
		}

		if (flag) {
			int nr = r + dr[(d + 2) % 4];
			int nc = c + dc[(d + 2) % 4];
			
			if (arr[nr][nc])
				break;
			else {
				r = nr;
				c = nc;
			}
		}
	}
	cout << answer;
	return 0;
}