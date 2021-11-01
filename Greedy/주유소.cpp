#include <iostream>
#define INF 1000000000
#define MAX 100000
using namespace std;

long long city[MAX] = { 0 };
long long oil[MAX] = { 0 };

int main() {
	int n;
	long long ans = 0;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
		cin >> city[i];
	for (int i = 0; i < n; i++)
		cin >> oil[i];
	long long temp = INF;
	for (int i = 0; i < n - 1; i++) {
		if (oil[i] < temp)
			temp = oil[i];
		ans += temp * city[i];
	}
	cout << ans;
	return 0;
}