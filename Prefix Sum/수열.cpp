#include <iostream>
#include <climits>
#define MAX 100003
using namespace std;

int arr[MAX] = { 0 };
int n, k;
int temp = INT_MIN;
int main() {
	cin >> n >> k;
	int sum = 0;
	int count = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		count++;
		if (count == k) {
			sum -= arr[i - k];
			if (sum > temp)
				temp = sum;
			count--;
		}
	}
	cout << temp;
	return 0;
}