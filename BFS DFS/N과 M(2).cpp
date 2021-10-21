#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m; 
	vector<int> arr;
	vector<int> ind;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		arr.push_back(i);
	}
	for (int i = 0; i < m; i++) {
		ind.push_back(1);
	}
	for (int i = 0; i < n - m; i++) {
		ind.push_back(0);
	}

	do {
		for (int i = 0; i < n; ++i) {
			if (ind[i] == 1) {
				cout << arr[i] << " ";
			}
		}
		cout << "\n";
	} while (prev_permutation(ind.begin(), ind.end()));
	
	return 0;
}

