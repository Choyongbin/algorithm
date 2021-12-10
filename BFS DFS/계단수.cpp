/*
#include <iostream>
#include <queue>
#include <vector>

#define mod 1000000000

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, ans = 0, cnt = 0, cur = 0, flag = 1;
	vector<bool> temp;
	queue < pair<int, pair<int, vector<bool>>>> q;
	cin >> n;
	if (n < 10) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i < 10; i++) {
		vector<bool> temp(10);
		temp[i] = 1;
		q.push(make_pair(1, make_pair(i, temp)));
	}

	while (!q.empty()) {
		cnt = q.front().first;
		temp = q.front().second.second;
		cur = q.front().second.first;
		q.pop();

		if (cnt == n) {
			flag = 1;
			for (int i = 0; i < 10; i++) {
				if (temp[i] == 0) {
					flag = 0;
					break;
				}
			}
			if (flag == 1) {
				ans = (ans + 1) % mod;
			}

		}
		else {
			if (cur + 1 < 10) {
				vector<bool> temp1 = temp;
				temp1[cur + 1] = 1;
				q.push(make_pair(cnt + 1, make_pair(cur + 1, temp1)));
			}
			if (cur - 1 > -1) {
				vector<bool> temp1 = temp;
				temp1[cur - 1] = 1;
				q.push(make_pair(cnt + 1, make_pair(cur - 1, temp1)));
			}
		}
	}

	cout << ans;
	return 0;
}

*/

#include<iostream>
using namespace std;
#define mod 1000000000

long long number = 0;
int dp[105][10][1024], n, ans;

int dfs(int idx, int num, int bit)
{
	number++;
	if (dp[idx][num][bit])
		return dp[idx][num][bit];
	if (idx == n) {
		return bit == (1 << 10) - 1 ? 1 : 0;
	}
	int res = 0;
	if (num + 1 < 10)
		res += dfs(idx + 1, num + 1, bit | 1 << (num + 1));
	if (num - 1 >= 0)
		res += dfs(idx + 1, num - 1, bit | 1 << (num - 1));

	return dp[idx][num][bit] = res %= mod;
}

int main()
{
	cin >> n;
	for (int i = 1; i < 10; i++)
	{
		ans += dfs(1, i, 1 << i);
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}