#include <iostream>

using namespace std;

int box[9][9];
bool col[9][9];
bool row[9][9];
bool sqr[9][9];


void Print() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << box[i][j];
		}
		cout << "\n";
	}
}

void dfs(int num) {
	int x = num / 9;
	int y = num % 9;

	if (num == 81) {
		Print();
		exit(0);
	}

	if (box[x][y] == 0) {
		for (int i = 1; i <= 9; i++) {
			if (row[x][i] == false && col[y][i] == false && sqr[(x / 3) * 3 + (y / 3)][i] == false) {
				row[x][i] = true;
				col[y][i] = true;
				sqr[(x / 3) * 3 + (y / 3)][i] = true;
				box[x][y] = i;
				dfs(num + 1);
				box[x][y] = 0;
				row[x][i] = false;
				col[y][i] = false;
				sqr[(x / 3) * 3 + (y / 3)][i] = false;

			}
		}
	}
	else
		dfs(num + 1);

}

void start() {
	for (int i = 0; i < 9; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < 9; j++) {
			box[i][j] = temp[j] - '0';
			if (box[i][j] != 0) {
				row[i][box[i][j]] = true;
				col[j][box[i][j]] = true;
				sqr[(i / 3) * 3 + (j / 3)][box[i][j]] = true;
			}
		}
	}

	dfs(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	start();

	return 0;
}