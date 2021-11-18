#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t, n, num1, num2;
	cin >> t;
	for (int test_case = 0; test_case < t; test_case++) {
		cin >> n;
		vector<pair<int, int>> em;
		for (int i = 0; i < n; i++) {
			cin >> num1 >> num2;
			em.push_back({ num1,num2 });
		}
		sort(em.begin(), em.end());
		int result = 1;
		int now = em[0].second;
		for (int i = 1; i < n; i++) {
			if (now > em[i].second) {
				now = em[i].second;
				result++;
			}
		}
		cout << result << "\n";
	}
	return 0;
}