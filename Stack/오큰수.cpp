#include <iostream>
#include <stack>
#define MAX 1000000
using namespace std; 

int arr[MAX] = { 0 };
int ans[MAX] = { 0 };

int main() {
	int n, temp;
	stack<int> st;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() && st.top() <= arr[i])
			st.pop();
		if (st.empty())
			ans[i] = -1;
		else
			ans[i] = st.top();
		st.push(arr[i]);
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}