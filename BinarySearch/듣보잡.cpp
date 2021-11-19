#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	int ans = 0;
	vector<string> arr1;
	vector<string> arr2;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		arr1.push_back(temp);
	}
	sort(arr1.begin(), arr1.end());
	for (int i = 0; i < m; i++) {
		string temp;
		cin >> temp;
		if (binary_search(arr1.begin(), arr1.end(), temp))
			arr2.push_back(temp);
	}
	sort(arr2.begin(), arr2.end());
	cout << arr2.size() << "\n";
	for (int i = 0; i < arr2.size(); i++) {
		cout << arr2[i] << "\n";
	}
	return 0;
}