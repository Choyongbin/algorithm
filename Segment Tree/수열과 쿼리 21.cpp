#include <iostream>
#define MAX 100001

long long arr[MAX] = { 0 };
long long tree[MAX * 4] = { 0 };

int n, m, cmd, k, a, b, x;

using namespace std;
/*
long long init(int start, int end, int node) {
	if (start == end)
		return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}
*/
void init(int start, int end, int node){
	if (start == end)
	{
		tree[node] = arr[start];
		return;
	}
	tree[node] = 0;
	int mid = (start + end) / 2;
	init(start, mid, node * 2);
	init(mid + 1, end, node * 2 + 1);
}
/*
void update(int start, int end, int node, int left, int right, long long diff) {
	if (left > end || right < start)
		return;
	if (left <= start && end <= right) {
		tree[node] += diff;
		if(start == end)
			return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, left, right, diff);
	update(mid + 1, end, node * 2 + 1, left, right, diff);
}
*/
void update(int start, int end, int node, int left, int right, long long diff){
	if (start > right || end < left) 
		return;
	if (left <= start && end <= right){
		tree[node] += diff;
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, left, right, diff);
	update(mid + 1, end, node * 2 + 1, left, right, diff);
}
/*
long long com(int start, int end, int node, int index) {
	if (index > end || index < start)
		return 0;
	if (start == end && end == index)
		return tree[node];
	int mid = (start + end) / 2;
	return com(start, mid, node * 2, index) + com(mid + 1, end, node * 2 + 1, index);
}
*/
long long com(int start, int end, int node, int index, long long ans){
	if (index < start || index > end) 
		return 0;
	ans += tree[node];
	if (start == end) 
		return ans; 
	int mid = (start + end) / 2;
	return com(start, mid, node * 2, index, ans) + com(mid + 1, end, node * 2 + 1, index, ans);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	init(1, n, 1);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> a >> b >> k;
			update(1, n, 1, a, b, k);
		}
		else {
			cin >> x;
			cout << com(1, n, 1, x, 0) << "\n";
		}
	}
	return 0;
}