#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string key, word;
		int sum = 0;
		vector<char> arr;
		vector<int> ans;
		cin >> key >> word;
		for (int i = 0; i < 26; i++) {
			arr.push_back(key[i]);
		}
		for (int i = 0; i < word.length(); i++) {
			int index = find(arr.begin(), arr.end(), word[i]) - arr.begin();
			ans.push_back(index+1);
		}
		for (int i = 0; i < ans.size()-1; i++) {
			sum += abs(ans[i] - ans[i + 1]);
		}
		cout << sum << "\n";
	}

	return 0;
}