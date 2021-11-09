#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, answer = 0, num;
	vector<int> arr;
	arr.push_back(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num > arr.back()) {
			arr.push_back(num);
			answer++;
		}
		else {
			auto it = lower_bound(arr.begin(), arr.end(), num);
			arr[it - arr.begin()] = num; // *it = num
		}
	}
	cout << answer << "\n";
	return 0;
}