#include <iostream>
#include <vector>

using namespace std;

int arr[501][501] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, answer;
	vector<vector<int>> tri;
	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<int> a;
		tri.push_back(a);
		for (int j = 0; j < i + 1; j++) {
			int temp;
			cin >> temp;
			tri[i].push_back(temp);
		}
	}
	
	answer = tri[0][0];
	arr[0][0] = tri[0][0];
	for (int i = 1; i < n; i++) {  // i: height j :width
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				arr[i][j] = arr[i-1][j] + tri[i][j];
			}
			else if (j == i) {
				arr[i][j] = arr[i-1][j - 1] + tri[i][j];
			}
			else {
				arr[i][j] = max(arr[i-1][j], arr[i - 1][j - 1]) + tri[i][j];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		answer = max(answer, arr[n-1][i]);
	}
	cout << answer;
	


	return 0;
}