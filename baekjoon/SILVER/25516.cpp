// 백준: 거리가 k이하인 트리 노드에서 사과 수확하기
// https://www.acmicpc.net/problem/25516
// 2024-02-04

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

std::vector<std::vector<int>> adj;
std::vector<int> apples;

int bfs(int k) {
    std::vector<bool> visited(adj.size(), false);
    std::queue<std::pair<int, int>> q; // 노드, 거리

    visited[0] = true;
    q.push({0, 0});

    int count = 0;

    while (!q.empty()) {
        int node = q.front().first;
        int distance = q.front().second;
        q.pop();

        if (distance <= k)
            count += apples[node];
        else
            break;

        for (int next : adj[node]) {
            if (!visited[next]) {
                q.push({next, distance + 1});
                visited[next] = true;
            }
        }
    }
    return count;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    adj.resize(n);
    apples.resize(n, 0);
    for (int i = 0; i < n - 1; ++i) {
        int p, c;
        std::cin >> p >> c;
        adj[p].push_back(c);
    }
    for (int i = 0; i < n; ++i) {
        int apple_num;
        std::cin >> apple_num;
        apples[i] = apple_num;
    }

    std::cout << bfs(k);
    return 0;
}