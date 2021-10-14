#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);

	priority_queue<int> h1; //최대
	priority_queue<int, vector<int>, greater<int>> h2; //최소
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (h1.size() == h2.size())
			h1.push(temp);
		else
			h2.push(temp);

		if (!h1.empty() && !h2.empty() && h1.top() > h2.top()) {
			int maxValue = h1.top();
			int minValue = h2.top();
			h1.pop();
			h2.pop();
			h1.push(minValue);
			h2.push(maxValue);
		}
		cout << h1.top() << "\n";
	}
	



	return 0;
}