// 백준: 알고리즘 수업 - 너비 우선 탐색 3
// https://www.acmicpc.net/problem/24446
// 2024-02-05

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int N, M, R;
std::vector<std::vector<int>> adj;
std::vector<bool> visited;
std::vector<int> depths;

void bfs() {
    std::queue<std::pair<int, int>> q; // 노드, 깊이
    q.push({R, 0});
    visited[R] = true;

    while (!q.empty()) {
        int current_node = q.front().first;
        int current_depth = q.front().second;
        q.pop();
        depths[current_node] = current_depth;

        for (const int next : adj[current_node]) {
            if (!visited[next]) {
                q.push({next, current_depth + 1});
                visited[next] = true;
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> N >> M >> R;
    adj.assign(N + 1, std::vector<int>());
    visited.assign(N + 1, false);
    depths.assign(N + 1, -1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs();
    for (int i = 1; i < depths.size(); ++i) {
        std::cout << depths[i] << "\n";
    }
    return 0;
}