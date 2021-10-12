#include <iostream>
#include <vector>

using namespace std;

vector<int> root;

int find(int a) {
	if (root[a] == a)
		return a;
	else
		return root[a] = find(root[a]);
}

void merge(int a, int b) {
	int pa = find(a);
	int pb = find(b);

	root[pb] = pa;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, cmd, a, b;

	cin >> n >> m;
	
	for (int i = 0; i <= n; i++) {
		root.push_back(i);
	}
	
	for (int i = 0; i < m; i++) {
		cin >> cmd >> a >> b;
		if (cmd == 0) {
			merge(a, b);
		}
		else {
			if (find(a) == find(b))
				cout << "YES" << "\n";
			else
				cout << "NO" << "\n";
		}
	}
	

	return 0;

}