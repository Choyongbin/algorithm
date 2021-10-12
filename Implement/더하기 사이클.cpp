#include <iostream>
#include <string>
using namespace std;

int answer = 0;
int  tmpAnswer = 0;

void solve(int a) {
    string str = "";
    string temp = "";
    int num;
    str = to_string(a);
    answer++;

    if (str.size() == 1) {
        temp += str[0];
        temp += str[0];
    }
    else {
        string aaa;
        num = (str[0] - '0') + (str[1] - '0');
        temp += str[1];
        aaa = to_string(num);
        temp += aaa[aaa.size() - 1];
    }
    if (tmpAnswer == stoi(temp)) {
        cout << answer;
        return;
    }
    else {
        solve(stoi(temp));
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a;
    cin >> a;
    tmpAnswer = a; 
    solve(a);
    return 0;
}