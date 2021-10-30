#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define MAX 1000000

int n, m, k, cmd, a;
long long b;
long long arr[MAX];
long long tree[MAX * 4] = { 0 };

long long init(int start, int end, int node) {
	if (start == end)
		return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}
// start : start index
// end : end index
// left , right : range
long long sum(int start, int end, int node, int left, int right) {
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, long long diff) {
	if (index > end || index < start)
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
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init(0, n-1, 1);
	for (int i = 0; i < m + k; i++) {
		cin >> cmd >> a >> b;
		if (cmd == 1) {
			update(0, n-1, 1, a-1, b - arr[a-1]);
			arr[a - 1] = b;
		}
		else {
			cout << sum(0, n-1, 1, a-1, b-1) << "\n";
		}
	}
	return 0;
}