#include <iostream>

using namespace std;

int arr[100][100];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0)
				arr[i][j] = 987654321;
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][k] + arr[k][j] < arr[i][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] ==  987654321)
				cout << 0 << ' ';
			else
				cout << 1 << ' ';
		}
		cout << "\n";
	}
	
	return 0;
}