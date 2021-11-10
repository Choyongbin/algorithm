#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;
int a[500000];
int n, m;
long long tree[2000000];

long long sum(int start, int end, int node, int left, int right) {
	if (end < left || start > right)
		return 0;
	if (left <= start && end >= left)
		return tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2+1, left, right) + sum(mid + 1, end, node * 2 + 2, left, right);
}

long long update(int start, int end, int node, int index, int diff) {
	if (index > end || index < start)
		return tree[node];
	if (start == end)
		return tree[node] = diff;
	int mid = (start + end) / 2;
	return tree[node] = update(start, mid, node * 2+1, index, diff) + update(mid + 1, end, node * 2 + 2, index, diff);
}


void com() {
	sort(arr.begin(), arr.end());
	//arr.erase(unique(arr.begin(), arr.end()), arr.end());
	for (int i = 0; i < n; i++) {
		a[i] = lower_bound(arr.begin(), arr.end(), a[i]) - arr.begin();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> m;
		arr.push_back(m);
		a[i] = m;
	}
	com();
	for (int i = 0; i < n; i++) {
		update(0, n - 1, 0, a[i], 1);	
		cout << (i + 1) - sum(0, n - 1, 0, 0, a[i]) << "\n";
	}
	return 0;
}