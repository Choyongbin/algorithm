#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

vector<int> node[50001];
vector<int> counts(20001, 0);
vector<int> visit(20001, 0);

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visit[start] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < node[x].size(); i++) {
            int y = node[x][i];
            if (visit[y] == 0) {
                q.push(y);
                visit[y] = 1;   
                counts[y] = counts[x] + 1;
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for (int i = 0; i < edge.size(); i++) {
        node[edge[i][0]].push_back(edge[i][1]);
        node[edge[i][1]].push_back(edge[i][0]);
    }
    bfs(1);
    sort(counts.begin(), counts.end(), greater<int>());
    for (int i = 0; i < counts.size(); i++) {
        if (counts[0] != counts[i])
            break;
        answer++;
    }
    cout << answer;
    return answer;
}

int main() {
    vector<vector<int>> edge;
    vector<int> a1;
    vector<int> a2;
    vector<int> a3;
    vector<int> a4;
    vector<int> a5;
    vector<int> a6;
    vector<int> a7;
    a1.push_back(1);
    a1.push_back(2);
    a2.push_back(2);
    a2.push_back(3);
    a3.push_back(3);
    a3.push_back(4);
    a4.push_back(4);
    a4.push_back(5);
    a5.push_back(2);
    a5.push_back(6);
    a6.push_back(6);
    a6.push_back(5);
    /*
    a7.push_back(5);
    a7.push_back(2);
    */
    edge.push_back(a1);
    edge.push_back(a2);
    edge.push_back(a3);
    edge.push_back(a4);
    edge.push_back(a5);
    edge.push_back(a6);
    //edge.push_back(a7);

    solution(6, edge);
    return 0;
}
