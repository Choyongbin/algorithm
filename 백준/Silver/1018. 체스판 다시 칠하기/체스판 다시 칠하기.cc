#include <iostream>

using namespace std;

char arr[50][50] = { 0 };

string WB[8] = {
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW"
};
string BW[8] = {
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB"
};
int main() {
	int n, m, ans = 987654321;
	string temp = "";

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		for (int j = 0; j < temp.length(); j++) {
			arr[i][j] = temp[j];
		}
	}
	int temp1 = n - 7;
	int temp2 = m - 7;

	for (int i = 0; i < temp2; i++) {
		for (int k = 0; k < temp1; k++) {
			int cntWB = 0;
			int cntBW = 0;
			for (int j = i; j < i + 8; j++) {
				for (int p = k; p < k + 8; p++) {
					if (arr[p][j] != WB[p%8][j%8])
						cntWB++;
					if (arr[p][j] != BW[p%8][j%8])
						cntBW++;
				}
			}
			ans = min(min(cntWB, cntBW), ans);
		}
	}

	cout << ans;

	return 0;
}