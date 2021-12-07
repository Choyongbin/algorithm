#include <iostream>

using namespace std;

int aa(int n, int m) {
	if (n % m == 0)
		return m;
	return aa(m, n % m);
}

int main() {
	int n, m;
	cin >> n >> m;
	cout << m - aa(n, m);
	return 0;
}

