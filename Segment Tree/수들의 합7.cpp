#include <iostream>
#define MAX 1000001
using namespace std;

long long arr[MAX] = { 0 };
long long tree[MAX * 4] = { 0 };

long long query(int start, int end, int node, int left, int right) {
	if (left > end || start > right)
		return 0;
	if (left <= start && right >= end)
		return tree[node];
	int mid = (start + end) / 2;
	return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, long long diff) {
	if (index < start || end < index)
		return;
	tree[node] += diff;
	if (start == end)
		return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, diff);
	update(mid + 1, end, node * 2 + 1, index, diff);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, a, b, c;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (a == 0) {
			if(b > c)
				cout << query(1, n, 1, c, b) << "\n";
			else
				cout << query(1, n, 1, b, c) << "\n";
		}
		else if (a == 1) {
			update(1, n, 1, b, c - arr[b]);
			arr[b] = c;
		}
	}
	return 0;
}