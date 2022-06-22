#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	double x, y, c;
	cin >> x >> y >> c;

	double left = 0, right = min(x, y);
	while (right - left >= 0.001) {
		double width = (left + right) / 2;
		double h1 = sqrt(pow(x, 2) - pow(width, 2));
		double h2 = sqrt(pow(y, 2) - pow(width, 2));
		double num = h1 * h2 / (h1 + h2);

		if (num < c)
			right = width;
		else
			left = width;
	}

	cout<<fixed;
	cout.precision(3);
	cout << right;
	return 0;
}