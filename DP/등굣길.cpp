#include <string>
#include <vector>
#include <iostream>

using namespace std;
int path[101][101] = { 0, };
int solution(int m, int n, vector<vector<int>> puddles) {
    path[0][0] = 1;
    path[1][0] = 1;
    path[0][1] = 1;
    for (int i = 0; i < puddles.size(); i++) {
        path[puddles[i][0]][puddles[i][1]] = -1;
    }
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << path[i][j];
        }
        cout << ""<<endl;
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int a = 0;
            int b = 0;
            if (path[i][j] == -1)
                continue;
            if (path[i - 1][j] != -1)
                a = path[i - 1][j];
            if (path[i][j - 1] != -1)
                b = path[i][j - 1];
            path[i][j] = a + b;
        }
    }
    cout << "" << endl;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << path[i][j];
        }
        cout << "" << endl;
    }
    return 0;
}

int main() {
    vector<vector<int>> a;
    vector<int> a1;
    a.push_back(a1);
    a[0].push_back(2);
    a[0].push_back(2);
    //cout << a[0][0];
    solution(4, 3, a);
    return 0;
}