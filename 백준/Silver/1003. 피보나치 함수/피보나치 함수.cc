#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long fibo[50] = { 0,1, };

long long fi(int n) {
    if (n == 0 || n==1)
        return fibo[n];
    else if (fibo[n] == 0)
        fibo[n] =  fi(n-2) + fi(n-1);
    return fibo[n];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, temp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp == 0)
            cout << "1 0\n";
        else
            cout << fi(temp - 1) << " " << fi(temp) << "\n";
    }
	return 0;
}