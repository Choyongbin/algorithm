#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int a[500][500];
    int answer = triangle[0][0];
    a[0][0] = triangle[0][0];

    int height = triangle.size();
    for (int i = 1; i < height; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                a[i][j] = a[i - 1][j] + triangle[i][j];
            }
            else if (j == i) {
                a[i][j] = a[i - 1][j - 1] + triangle[i][j];
            }
            else {
                a[i][j] = max(a[i - 1][j - 1], a[i - 1][j]) + triangle[i][j];
            }
        }
    }
    for (int i = 0; i < height; i++) {
        answer = max(answer, a[height - 1][i]);
    }
    return answer;
}