// 백준: 트리와 쿼리
// https://www.acmicpc.net/problem/15681
// 2024-06-13

/*
루트에 대해서 DFS를 돌리며 재귀적으로 서브트리 사이즈를 메모이제이션하기
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> subtree_size;
vector<bool> visited;

int dfs(int node) {
    visited[node] = true;
    int size = 1; // 자기 자신 포함
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            size += dfs(neighbor);
        }
    }
    subtree_size[node] = size;
    return size;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, R, Q; // 정점, 루트, 쿼리 수
    cin >> N >> R >> Q;
    adj.assign(N + 1, vector<int>());
    subtree_size.assign(N + 1, 0);
    visited.assign(N + 1, false);
    for (int i = 0; i < N - 1; ++i) {
        int U, V;
        cin >> U >> V;
        adj[U].push_back(V);
        adj[V].push_back(U); // 양방향 그래프
    }

    dfs(R); // 루트부터 DFS 시작

    for (int i = 0; i < Q; ++i) {
        int U;
        cin >> U;
        cout << subtree_size[U] << "\n";
    }
    return 0;
}