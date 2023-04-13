#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> arr;

constexpr auto MAX = 2000000000;

int dist(int high, int low) {
	int lowX = arr[low].first;
	int lowY = arr[low].second;
	int highX = arr[high].first;
	int highY = arr[high].second;

	int distX = highX - lowX;
	int distY = highY - lowY;

	return (distX * distX) + (distY * distY);
}

int solve(int low, int high) {
	if (low == high)
		return MAX;

	if (low + 1 >= high)
		return dist(high, low);

	int distMin = dist(high, low);
	int mid = (low + high) / 2;
	int leftMin = solve(low, mid);
	int rightMin = solve(mid + 1, high);

	if (leftMin < distMin)
		distMin = leftMin;

	if (rightMin < distMin)
		distMin = rightMin;

	vector<pair<int, int>> temp;

	for (int i = low; i <= high; i++) {
		int d = arr[i].first - arr[mid].first;
		if (d * d < distMin)
			temp.push_back({ arr[i].second, arr[i].first });
	}

	int len = temp.size();

	if (len == 0)
		return distMin;

	sort(temp.begin(), temp.end());

	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			int y = temp[i].first - temp[j].first;
			int x = temp[i].second - temp[j].second;

			if ((y * y) < distMin) {
				int dd = (x * x) + (y * y);
				if (dd < distMin) {
					distMin = dd;
				}
			}
			else {
				break;
			}
		}
	}

	return distMin;
}

int main() {
	int n;

	cin >> n;	

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		arr.push_back({ x,y });
	}

	sort(arr.begin(), arr.end());
	
	cout << solve(0, n - 1);
	return 0;
}