#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str = "";
	string temp = "";
	int flag = 0;
	int answer = 0;
	cin >> str;

	for (int i = 0; i <= str.size(); i++) {
		if (str[i] == '+' || str[i] == '\0') {
			if (flag == 0) {
				answer += stoi(temp);
			}
			else {
				answer -= stoi(temp);
			}
			temp = "";
		}
		else if (str[i] == '-') {
			if (flag == 0) {
				answer += stoi(temp);
			}
			else {
				answer -= stoi(temp);
			}
			temp = "";
			flag = 1;
		}
		else {
			temp += str[i];
		}
	}

	cout << answer;

	return 0;

}