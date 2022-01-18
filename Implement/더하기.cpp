#include <iostream>
#include <cstring>
using namespace std;


int main() {
	char a[101];
	char* b;
	int sum = 0;
	cin >> a;
	b = strtok(a, ",");
	while (b != NULL) {
		sum += atoi(b);
		b = strtok(NULL, ",");
	}
	cout << sum;
	return 0;
}