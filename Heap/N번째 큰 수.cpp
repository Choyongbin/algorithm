#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue<int> pq;
	int n,num;
	cin >> n;
	for (int i = 0; i < n * n; i++) {
		cin >> num;
		pq.push(-num);
		if (pq.size() > n)
			pq.pop();
	}
	cout << -pq.top();
	return 0;
}