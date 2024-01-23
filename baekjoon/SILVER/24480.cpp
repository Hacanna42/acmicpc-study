// 백준: 알고리즘 수업 - 깊이 우선 탐색 2
// https://www.acmicpc.net/problem/24480
// 2024-01-23

#include <algorithm>
// #include <functional>
#include <iostream>
#include <vector>

std::vector<int> adj[100001];
std::vector<bool> visited;
std::vector<int> order;

int cnt = 1;
void dfs(int node) {
    visited[node] = true;
    order[node] = cnt++;
    for (const int next : adj[node]) {
        if (!visited[next]) dfs(next);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N, M, R;
    std::cin >> N >> M >> R;

    // 벡터 초기화
    visited.assign(N + 1, false);
    order.assign(N + 1, 0);
    for (int i = 0; i < M; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; ++i) {
        std::sort(adj[i].begin(), adj[i].end(),
                  [](int a, int b) { return a > b; });
    }

    dfs(R);

    for (int i = 1; i <= N; ++i) {
        std::cout << order[i] << "\n";
    }
    return 0;
}