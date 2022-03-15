#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s1, s2, ans = "";
    cin >> s1 >> s2;
    while (!s1.empty() && s1[0] != '1') {
    	s1.erase(0, 1);
	}
    while (!s2.empty() && s2[0] != '1') {
    	s2.erase(0, 1);
	}
    if (s1.empty() && s2.empty()) {
        cout << '0' << "\n";
        return 0;
    }
    else if (s1.empty() && !s2.empty()) {
        cout << s2 << "\n";
        return 0;
    }
    else if (!s1.empty() && s2.empty()) {
        cout << s1 << "\n";
        return 0;
    }
    int carry = 0;
    // i for s1
    int i = s1.length() - 1;
    // j for s2
    int j = s2.length() - 1;
    while (max(i, j) >= 0) {
        int a = (i < 0) ? 0 : s1[i] - '0';
        int b = (j < 0) ? 0 : s2[j] - '0';
        int c = a + b + carry;
        carry = c / 2;
        c %= 2;
        ans.insert(0, to_string(c));
        --i;
        --j;
    }
    
    if (carry == 1) {
        ans.insert(0, "1");
    }
    cout << ans << "\n";
    
}