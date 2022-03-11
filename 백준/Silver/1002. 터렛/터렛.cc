#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int t, x1, y1, r1, x2, y2, r2;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		int dist = pow(x1 - x2, 2) + pow(y1 - y2, 2); //두 좌표 사이의 거리
		int dist2 = pow(r1 + r2, 2); //반지름의 합
		int dist3 = pow(r1 - r2, 2); //반지름의 차

		if (dist == 0) {
			if (dist3 == 0)
				cout << -1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (dist == dist2 || dist == dist3)
			cout << 1 << "\n";
		else if (dist2 > dist&& dist3 < dist)
			cout << 2 << "\n";
		else
			cout << 0 << "\n";
	}
	return 0;
}