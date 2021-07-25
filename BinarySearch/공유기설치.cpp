#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int houseNum, int routerNum, vector<int> location) {
	int answer = 0;
	sort(location.begin(), location.end());
	int left = 1;
	int right = location[location.size()-1] - location[0];
	int current = location[0];
	int count = 0;

	while (left <= right) {
		current = location[0];
		count = 1;
		int mid = 0;
		for (int i = 1; i < location.size(); i++) {
			mid = (left + right) / 2;
			int deff = location[i] - current;

			if (mid <= deff) {
				count++;
				current = location[i];
			}
		}
		if (count >= routerNum) {
			answer = max(answer, mid);
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}

	}	
		
	return answer;
}

int main() {
	int answer = 0;
	int houseNum = 0;
	int routerNum = 0;
	int a = 0;

	cin >> houseNum >> routerNum;
	vector<int> location(houseNum);

	for (int i = 0; i < houseNum; i++) {
		cin >> location[i];
	}

	answer = solution(houseNum, routerNum, location);
	printf("%d", answer);
	return 0;
}