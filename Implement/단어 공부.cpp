#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str = "";
	int max=0, index=0, arr[26] = { 0 };
	string a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ?";
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		str[i] = toupper(str[i]);
		arr[a.find(str[i])]++;  //******************************
	}

	for (int i = 0; i < 26; i++) {
		if (arr[i] == 0)
			continue;
		if (max == arr[i]) {
			index = 26;
			continue;
		}
		if (max < arr[i]) {
			max = arr[i];
			index = i;
		}
	}
	cout << a[index];

	return 0;
}