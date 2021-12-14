#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100001
#define def 1987654321

long long arr[MAX];
long long tree[4 * MAX];

long long init(int start, int end, int node) {
	if (start == end)
		return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

long long query(int start, int end, int node, int left, int right) {
	if (left > end || right < start)
		return def;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	return min(query(start, mid, node * 2, left, right), query(mid + 1, end, node * 2 + 1, left, right));
}

int main() {
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init(0, n - 1, 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << query(0, n - 1, 1, a - 1, b - 1) << "\n";
	}
	return 0;
}