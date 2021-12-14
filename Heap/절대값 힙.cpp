#include <queue>
#include <iostream>

using namespace std;

struct oper {
	bool operator()(long long a, long long b) {
		if (abs(a) == abs(b))
			return a > b;
		else
			return abs(a) > abs(b);
	}
};



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	long long num;
	priority_queue<long long, vector<long long>, oper> q;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num == 0) {
			if (q.empty())
				cout << 0 << "\n";
			else {
				cout << q.top() << "\n";
				q.pop();
			}
		}
		else {
			q.push(num);
		}
	}
	return 0;
}