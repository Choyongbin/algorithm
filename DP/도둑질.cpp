#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int memo1[1000010] = { 0 };
    int memo2[1000010] = { 0 };
    memo1[0] = money[0];
    memo1[1] = money[0];
    memo2[1] = money[1];

    for (int i = 2; i < money.size() - 1; i++) {
        memo1[i] = max(memo1[i - 1], memo1[i - 2] + money[i]);
    }
    for (int i = 2; i < money.size(); i++) {
        memo2[i] = max(memo2[i - 1], memo2[i - 2] + money[i]);
    }
    answer = max(memo1[money.size() - 2], memo2[money.size() - 1]);
    return answer;
}