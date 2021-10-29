#include <iostream>
#include <queue>
#include <vector>

using namespace std; 

int main() {
	int n, k;
	cin >> n >> k;
	queue<int> q;
	vector<int> arr;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (!q.empty()) {
		for (int i = 0; i < k-1; i++) {
			int temp = q.front();
			q.pop();
			q.push(temp);
		}
		int temp = q.front();
		q.pop();
		arr.push_back(temp);
	}
	cout << "<";
	for (int i = 0; i < n; i++) {
		if (i == n - 1)
			cout << arr[i] << ">";
		else
			cout << arr[i] << ", ";
	}
	
	return 0;
}