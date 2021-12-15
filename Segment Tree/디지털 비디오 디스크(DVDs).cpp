#include <iostream>
#include <vector>
#define def 1000000007
using namespace std;

int arr[100001];

pair<int, int> init(vector<pair<int, int>>& tree, int start, int end, int node) {
	if (start == end)
		return tree[node] = make_pair(arr[start], arr[start]);
	int mid = (start + end) / 2;
	pair<int, int> temp1 = init(tree, start, mid, node * 2);
	pair<int, int> temp2 = init(tree, mid + 1, end, node * 2 + 1);
	return tree[node] = make_pair(min(temp1.first, temp2.first), max(temp1.second, temp2.second));
}
/*
pair<int,int> change_qurey(vector<pair<int,int>> &tree, int start, int end, int node, int index, int diff) {
	if (start > index || end < index)
		return tree[node];
	if (start == end) {
		if (tree[node].first > diff)
			tree[node].first = diff;
		else if (tree[node].second < diff)
			tree[node].second = diff;
		return tree[node];
	}
	int mid = (start + end) / 2;
	pair<int, int> temp1 = change_qurey(tree, start, mid, node * 2, index, diff);
	pair<int, int> temp2 = change_qurey(tree, mid + 1, end, node * 2 + 1, index, diff);
	return tree[node] = make_pair(min(temp1.first, temp2.first), max(temp1.second, temp2.second));

}
*/
void change_qurey(vector<pair<int, int>>& tree, int start, int end, int node, int index, int diff) {
	if (start > index || end < index)
		return;
	if (start == end) {
		tree[node].first = diff;
		tree[node].second = diff;
	}
	else {
		int mid = (start + end) / 2;
		change_qurey(tree, start, mid, node * 2, index, diff);
		change_qurey(tree, mid + 1, end, node * 2 + 1, index, diff);
		tree[node] = make_pair(min(tree[node * 2].first, tree[node * 2 + 1].first), max(tree[node * 2].second, tree[node * 2 + 1].second));
	}

}

pair<int, int> query(vector<pair<int, int>>& tree, int start, int end, int node, int left, int right) {
	if (left > end || right < start)
		return make_pair(def, 0);
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	pair<int, int> temp1 = query(tree, start, mid, node * 2, left, right);
	pair<int, int> temp2 = query(tree, mid + 1, end, node * 2 + 1, left, right);
	return make_pair(min(temp1.first, temp2.first), max(temp1.second, temp2.second));
}

int main() {
	int t, n, k, q, a, b;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> k;
		vector<pair<int, int>> tree(n * 4);
		for (int j = 0; j < n; j++) {
			arr[j] = j;
		}
		init(tree, 0, n - 1, 1);
		
		for (int j = 0; j < k; j++) {
			cin >> q >> a >> b;
			if (q == 0) {
				change_qurey(tree, 0, n - 1, 1, a, arr[b]);
				change_qurey(tree, 0, n - 1, 1, b, arr[a]);
				
				int temp = arr[b];
				arr[b] = arr[a];
				arr[a] = temp;
			}
			else if (q == 1) {
				pair<int, int> kk = query(tree, 0, n - 1, 1, a, b);
				//cout << "dddddddddd "<< kk.first << " "<< kk.second << "\n";
				if (kk.first == a && kk.second == b)
					cout << "YES\n";
				else
					cout << "NO\n";
			}
		}
	}
	return 0;
}