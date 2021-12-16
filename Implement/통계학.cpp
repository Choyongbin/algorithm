#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}

int ave(vector<int> a) {
	double sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i];
	return (int)floor((sum / n) + 0.5);
}

int midNum(vector<int> a) {
	return a[n / 2];
}

int most(vector<int> a) {
	if (n == 1)
		return a[0];
	vector<pair<int, int>> temp;
	for (int i = 0; i < n; i++) {
		if (temp.empty()) {
			temp.push_back(make_pair(a[i], 1));
			continue;
		}
		if (temp.back().first == a[i]) {
			pair<int, int> tmp = temp.back();
			tmp.second++;
			temp.pop_back();
			temp.push_back(tmp);
		}
		else
			temp.push_back(make_pair(a[i], 1));
	}
	sort(temp.begin(), temp.end(), cmp);
	if (temp[0].second == temp[1].second)
		return temp[1].first;
	else
		return temp[0].first;
}

int range(vector<int> a) {
	return a[n - 1] - a[0];
}

int main() {
	cin >> n;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		a.push_back(num);
	}
	sort(a.begin(), a.end());
	cout << ave(a) << "\n" << midNum(a) << "\n" << most(a) << "\n" << range(a) << "\n";
	return 0;
}