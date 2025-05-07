#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, i, j;
	int arr[1001];
	vector<int> arr2;

	cin >> N;

	for ( i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	for (i = 0; i < N; i++) {
		for (j = i; j < N; j++) {
			arr2.push_back(arr[i] + arr[j]);
		}
	}

	sort(arr2.begin(), arr2.end());

	for (i = N - 1; i >= 0; i--) {
		for (j = i; j >= 0; j--) {
			if (binary_search(arr2.begin(), arr2.end(), arr[i] - arr[j])) {
				cout << arr[i] << "\n";
				return 0;
			}
		}
	}
	
	return 0;
}