#include <iostream>

using namespace std;

int n, m, b;
int ground[500][500];
int answer = 987654321;
int ansHeight = 0;

void makeBlock(int height) {
	int block = 0;
	int remove = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ground[i][j] > height)
				remove += ground[i][j] - height;
			else if (ground[i][j] < height)
				block += height - ground[i][j];
		}
	}

	//cout <<height << " " << remove << " " << block << "\n";
	
	if (remove + b < block)
		return;
	else {
		if (answer > remove * 2 + block) {
			answer = remove * 2 + block;
			ansHeight = height;
		}
		else if (answer == remove * 2 + block) {
			ansHeight = height;
		}
	}
	/*cout << "Answer\n";
	cout << answer << " " << ansHeight << "\n";
	cout << "---------\n";*/
}

int main() {
	int minblock = 987654321;
	int maxblock = 0;
	cin >> n >> m >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ground[i][j];
			if (ground[i][j] < minblock)
				minblock = ground[i][j];
			if (ground[i][j] > maxblock)
				maxblock = ground[i][j];
		}
	}

	/*cout << "------------------------\n";
	cout << minblock << " " << maxblock << "\n";
	cout << "------------------------\n";*/

	for (int i = minblock; i < maxblock + 1; i++) {
		makeBlock(i);
	}

	cout << answer << " " << ansHeight;
	
	return 0;
}
