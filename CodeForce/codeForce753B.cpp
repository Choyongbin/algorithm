#include <iostream>

using namespace std;

int main() {
	int t;
	long long x, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> x >> n;
		long long dif = n / 4;
		long long mod = n % 4;
		if (x % 2 == 0) {
			if (mod == 0) {
				cout << x << "\n";
			}
			else if (mod == 1) {
				cout << x - 1 - (4*dif) << "\n";
			}
			else if (mod == 2) {
				cout << x + 1 << "\n";
			}
			else {
				cout << x + (4 * (dif+1)) << "\n";
			}
		}
		else {
			if (mod == 0) {
				cout << x << "\n";
			}
			else if (mod == 1) {
				cout << x + 1 + (4 * dif) << "\n";
			}
			else if (mod == 2) {
				cout << x - 1 << "\n";
			}
			else {
				cout << x - (4 * (dif+1)) << "\n";
			}
		}
		
		
	}	
	return 0;
}

// Á¡ÇÁÇÏ±â Àü¿¡ ÁÂÇ¥°¡ Â¦¼ö : ¿ÞÂÊ(-)
// Á¡ÇÁÇÏ±â Àü¿¡ ÁÂÇ¥°¡ È¦¼ö : ¿À¸¥ÂÊ(+)
/*

Â¦¼ö ½ÃÀÛ
0 10(x)
1 9(x -1 - x * 0)
2 11 (x +1)
3 14 (x + 4*1)
4 10(x)

5 5(x - 1 - 4* 1)
6 11(x+1)
7 18(x + 4*2)
8 10(x)

È¦¼ö ½ÃÀÛ
0 177(x)
1 178(x+1+4*0)
2 176(x-1)
3 173(x-4*1)
4 177(x)

5 182(x+1+4*1)
6 176(x-1)
7 169(x-4*2)
8 177(x)

9 186(x+1+4*3)
10 176(x-1)
11 165(x-4*3)
12 177(x)


1 -1
2 1
3 4
4 0

5 -5
6 1
7 8
8 0

9 -9
10 1
11 12
12 0
*/