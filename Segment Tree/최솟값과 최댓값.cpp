#include <iostream>
#include <vector>

#define MAX 100000
#define def 1000000007
using namespace std;

long long arr[MAX] = { 0 };
int n, m;
long long a, b;
// min , max

pair<long long, long long> init(vector<pair<long long, long long>> &tree, int start, int end, int node) {
	if (start == end)
		return tree[node] = make_pair(arr[start], arr[start]);
	int mid = (start + end) / 2;
	pair<long long, long long> temp1 = init(tree, start, mid, node * 2);
	pair<long long, long long> temp2 = init(tree, mid+1, end, node * 2 + 1);
	return tree[node] = make_pair(min(temp1.first, temp2.first), max(temp1.second, temp2.second));
}

pair<long long, long long> query(vector<pair<long long, long long>> &tree, int start, int end, int node, int left, int right) {
	if (left > end || right < start)
		return make_pair(def, 0);
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	pair<long long, long long> temp1 = query(tree, start, mid, node * 2, left, right);
	pair<long long, long long> temp2 = query(tree, mid + 1, end, node * 2 + 1, left, right);
	return make_pair(min(temp1.first, temp2.first), max(temp1.second, temp2.second));
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<pair<long long, long long>> tree(n * 4);
	init(tree, 0, n - 1, 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << query(tree, 0, n - 1, 1, a-1, b-1).first << " " << query(tree, 0, n - 1, 1, a-1, b-1).second << "\n";
	}
	return 0;
}