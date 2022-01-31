#include <iostream>

using namespace std;


int num[11];
int oper[4];
int n;
int maxNum = -1000000001;
int minNum = 1000000001;

void solution(int cur, int count) {
	cout << cur << "\n";
	if (count == n) {
		if (cur > maxNum)
			maxNum = cur;
		if (cur < minNum)
			minNum = cur;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (oper[i] > 0) {
			oper[i]--;
			if (i == 0) solution(cur + num[count], count + 1);
			else if (i == 1) solution(cur - num[count], count + 1);
			else if (i == 2) solution(cur * num[count], count + 1);
			else solution(cur / num[count], count + 1);
			oper[i]++;
		}
	}
	return;
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}
	solution(num[0], 1);

	cout << maxNum << "\n" << minNum;

	return 0;
}