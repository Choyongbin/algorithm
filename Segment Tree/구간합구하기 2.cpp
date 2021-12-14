#include <iostream>

#define MAX 1000001
using namespace std;

long long arr[MAX];
long long Lazy[4 * MAX];
long long tree[4 * MAX];

long long init(int start, int end, int node) {
	if (start == end) 
		return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

void lazy_update(int start, int end, int node) {
	if (Lazy[node] != 0) {
		tree[node] = tree[node] + (end - start + 1) * Lazy[node];
		if (start != end) {
			Lazy[node * 2] = Lazy[node * 2] + Lazy[node];
			Lazy[node * 2 + 1] = Lazy[node * 2 + 1] + Lazy[node];
		}
		Lazy[node] = 0;
	}
}

void update(int start, int end, int node, int left, int right, long long diff) {
	lazy_update(start, end, node);
	if (right < start || left > end) 
		return;
	if (left <= start && end <= right)
	{
		tree[node] = tree[node] + (end - start + 1) * diff;
		if (start != end)
		{
			Lazy[node * 2] = Lazy[node * 2] + diff;
			Lazy[node * 2 + 1] = Lazy[node * 2 + 1] + diff;
		}
		return;
	}

	int mid = (start + end) / 2;
	update(start, mid, node * 2, left, right, diff);
	update(mid + 1, end, node * 2 + 1, left, right, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(int start, int end, int node, int left, int right) {
	lazy_update(start, end, node);
	if (right < start || left > end)
		return 0;
	if (left <= start && right >= end)
		return tree[node];
	int mid = (start + end) / 2;
	return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, k, a, b, c, d;

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	init(1, n, 1);
	for (int i = 0; i < m + k; i++) {
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			update(1, n, 1, b, c, d);
		}
		else if (a == 2) {
			cin >> b >> c;
			cout << query(1, n, 1, b, c) << "\n";
		}
	}
	return 0;
}