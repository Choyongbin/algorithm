#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long a, b;
	int cnt = 1;
	queue<pair<long long,int>> q;
	cin >> a >> b;
	q.push({ a,1 });
	while (!q.empty()) {
		long long na = q.front().first;
		int ncnt = q.front().second;
		q.pop();
		if (na < b) {
			ncnt++;
			long long c = na * 2;
			long long d = na * 10 + 1;
			if (c == b || d == b) {
				cnt = ncnt;
				break;
			}
			q.push({ c,ncnt });
			q.push({ d,ncnt });
		}
	}
	if (cnt == 1) {
		cout << -1 << "\n";
	}
	else {
		cout << cnt << "\n";
	}
	
	return 0;
}