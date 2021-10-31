#include <iostream>
#define MAX 1000000
#define def 1000000007
using namespace std;

int n, m, k, cmd, a, b;

int arr[MAX] = { 0 };
int tree[MAX * 4] = { 0 };

long long init(int start, int end, int node) {
	if (start == end) 
		return tree[node] = arr[start] % def;
	int mid = (start + end) / 2;
	return tree[node] = (init(start, mid, node * 2) * init(mid + 1, end, node * 2 + 1)) % def;
}

long long sum(int start, int end, int node, int left, int right) {
	if (left > end || right < start)
		return 1;
	if (left <= start && end <= right)
		return tree[node] % def;
	int mid = (start + end) / 2;
	return (sum(start, mid, node * 2, left, right) * sum(mid + 1, end, node * 2 + 1, left, right)) % def;
}

long long update(int start, int end, int node, int index, int after) {
	if (index > end || index < start)
		return tree[node];
	if (start == end)
		return tree[node] = after;
	int mid = (start + end) / 2;
	return tree[node] = update(start, mid, node * 2, index, after) * update(mid + 1, end, node * 2 + 1, index, after) % def;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init(0, n - 1, 1);
	for (int i = 0; i < m + k; i++) {
		cin >> cmd >> a >> b;
		if (cmd == 1) {
			update(0, n - 1, 1, a - 1, b);
			arr[a - 1] = b;
		}
		else {
			cout << sum(0, n - 1, 1, a - 1, b - 1) <<"\n";
		}
	}
	return 0;
}