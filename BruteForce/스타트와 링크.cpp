#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[21][21];
int minNum = 987654321;

void solution(vector<int> a, vector<int> b) {
	int aTemp = 0;
	int bTemp = 0;
	for (int i = 0; i < a.size(); i++) {
		for (int j = i+1; j < a.size(); j++) {
			aTemp += arr[a[i]][a[j]];
			aTemp += arr[a[j]][a[i]];
		}
	}
	for (int i = 0; i < b.size(); i++) {
		for (int j = i + 1; j < b.size(); j++) {
			bTemp += arr[b[i]][b[j]];
			bTemp += arr[b[j]][b[i]];
		}
	}
	if (abs(aTemp - bTemp) < minNum)
		minNum = abs(aTemp - bTemp);
	return;
}

int main() {
	int n;
	vector<int> all;
	vector<int> temp;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		all.push_back(i);
	}
	for (int i = 0; i < n / 2; i++) {
		temp.push_back(1);
	}
	for (int i = 0; i < n / 2; i++) {
		temp.push_back(0);
	}
	do {
		vector<int> aTeam;
		vector<int> bTeam;
		for (int i = 0; i < n; i++) {
			if (temp[i] == 1)
				aTeam.push_back(all[i]);
			else
				bTeam.push_back(all[i]);
		}
		solution(aTeam, bTeam);
	} while (prev_permutation(temp.begin(), temp.end()));
	cout << minNum;
	return 0;
}