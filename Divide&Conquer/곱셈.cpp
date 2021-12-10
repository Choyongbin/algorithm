#include <iostream>

using namespace std;

long long divide(long long a, long long b, long long c) {
	a = a % c;
	if (b == 1)
		return a;
	if (b == 0)
		return 1;
	if (b % 2)
		return a * divide(a, b - 1, c) % c;
	return divide(a * a, b / 2, c) % c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long a, b, c;
	cin >> a >> b >> c;
	cout << divide(a, b,c);
	return 0;
}