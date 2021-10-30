#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m,sum = 0, a,b;
	vector<int> arr;
	arr.push_back(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		sum += temp;
		arr.push_back(sum);
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << arr[b] - arr[a-1] << "\n";
	}
	return 0;
}