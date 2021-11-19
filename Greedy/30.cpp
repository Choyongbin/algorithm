#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string n;
	long long sum = 0;
	int flag = 1;
	cin >> n;
	for (int i = 0; i < n.length(); i++) {
		sum += n[i];
		if (n[i] == '0')
			flag = 0;
	}
	if (sum % 3 == 0 && flag == 0) {
		sort(n.begin(), n.end(), greater<char>());
		cout << n;
	}
	else
		cout << -1;	
	return 0;
}