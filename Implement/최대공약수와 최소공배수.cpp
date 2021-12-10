#include <iostream>

using namespace std;

int greatestCommonFactor(int a, int b) {
	if (b == 0) {
		return a;
	}
	return greatestCommonFactor(b, a % b);
}

int LeastCommonMultiple(int a, int b) {
	return (a * b) / greatestCommonFactor(a, b);
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << greatestCommonFactor(a, b) << "\n" << LeastCommonMultiple(a,b);
	return 0;
}