// 백준: 알고리즘 수업 - 너비 우선 탐색 1
// https://www.acmicpc.net/problem/24444
// 2024-01-23

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

std::vector<int> adj[100001];
std::vector<bool> visited(100001, false);
std::vector<int> order(100001, 0);

void bfs(int start) {
    std::queue<int> q;
    visited[start] = true;
    q.push(start);
    int cnt = 1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        order[current] = cnt++;

        for (int next : adj[current]) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N, M, R;
    std::cin >> N >> M >> R;
    for (int i = 0; i < M; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; ++i) {
        std::sort(adj[i].begin(), adj[i].end());
    }

    bfs(R);

    for (int i = 1; i <= N; ++i) {
        std::cout << order[i] << "\n";
    }
    return 0;
}