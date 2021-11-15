#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	int n;
	vector<int> a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		a.push_back(num);
	}
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		b.push_back(num);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i] * b[i];
	}
	cout << sum;
	return 0;
}