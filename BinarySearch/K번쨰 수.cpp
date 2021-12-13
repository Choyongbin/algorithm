#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	int low = 1;
	int high = k;
	int result = -1;

    while (low <= high){
        int cnt = 0;
        int mid = (low + high) / 2;
        for (int i = 1; i <= n; i++)
            cnt += min(mid / i, n); 
        if (cnt < k)
            low = mid + 1;
        else{
            result = mid;
            high = mid - 1;
        }
    }
    cout << result << "\n";
    return 0;

}
