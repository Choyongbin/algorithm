#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[21];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, s;
	vector<int> temp;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < (1<<n); i++) {
		int sum = 0;
		int flag = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				sum += arr[j];
				flag = 1;
			}
		}
		if(flag == 1)
			temp.push_back(sum);
	}
	
	sort(temp.begin(), temp.end());
	for (int i = 0; i < (1 << n)-1; i++)
		cout << temp[i] << " ";
	int low = lower_bound(temp.begin(), temp.end(), s) - temp.begin();
	int hig = upper_bound(temp.begin(), temp.end(), s) - temp.begin();
	cout << hig - low;
	
	return 0;
}