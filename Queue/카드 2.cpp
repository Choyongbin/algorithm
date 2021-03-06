#include <iostream>
#include <deque>

using namespace std;

int main() {
	int n;
	deque<int> dq;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	while (dq.size() != 1) {
		dq.pop_front();
		int temp = dq.front();
		dq.pop_front();
		dq.push_back(temp);
	}

	cout << dq.front();
	return 0;
}