#include <iostream>

using namespace std;

int arr[100][100];

int main() {
	int n, m, a, b, c;
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = 987654321;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if(arr[a-1][b-1] > c)
			arr[a-1][b-1] = c;
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
			if (arr[i][j] == 987654321 || i==j)
				cout << 0 << " ";
			else
				cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}