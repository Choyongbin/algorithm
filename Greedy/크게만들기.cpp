#include <iostream>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	string temp;
	deque<int> dq;
	cin >> n >> k >> temp;
	for (int i = 0; i < temp.length(); i++) {
		while (k != 0 && !dq.empty() && dq.back() < temp[i] - '0') {
			dq.pop_back();
			k--;
		}
		dq.push_back(temp[i] - '0');
	}
	for (int i = 0; i < dq.size()-k; i++) {
		cout << dq[i];
	}
	return 0;
}