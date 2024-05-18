// 백준: 트리의 부모 찾기
// https://www.acmicpc.net/problem/11725
// 2024-05-16

/*
입력으로 주어진 데이터는 간선 정보일 뿐이다.
어느 방향인지는 주어진적이 없다. 그저 문제를 읽은 나의 착각일 뿐..
*/

#include <iostream>
#include <vector>
using namespace std;

void dfs(int start, vector<int> &parents, vector<vector<int>> &adj) {
    for (const auto &next : adj[start]) {
        if (parents[next] == -1) { // 아직 탐색되지 않았으면
            parents[next] = start; // 부모 삽입
            dfs(next, parents, adj);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<vector<int>> adj(N + 1, vector<int>());
    vector<int> parents(N + 1, -1);
    for (int i = 0; i < N - 1; ++i) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    dfs(1, parents, adj);
    for (int i = 2; i < parents.size(); ++i) {
        cout << parents[i] << "\n";
    }

    return 0;
}