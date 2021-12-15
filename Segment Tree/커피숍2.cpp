#include <iostream>
#define MAX 100001
using namespace std;

long long arr[MAX];
long long tree[MAX * 4];

long long init(int start, int end, int node) {
	if (start == end)
		return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

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
	int n, q, a, x, y;
	long long b;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	init(1, n, 1);
	for (int i = 0; i < q; i++) {
		cin >> x >> y >> a >> b;
		if(x > y)
			cout << query(1, n, 1, y, x) << "\n";
		else
			cout << query(1, n, 1, x, y) << "\n";
		update(1, n, 1, a, b - arr[a]);
		arr[a] = b;
	}
	return 0;
}