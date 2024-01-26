// 백준: 이분 그래프
// https://www.acmicpc.net/problem/1707
// 2024-01-26

#include <iostream>
#include <stack>
#include <vector>

std::vector<std::vector<int>> adj;
std::vector<int> visited;

bool dfs(int start) {
    std::stack<int> stack;
    stack.push(start);
    visited[start] = 1;

    while (!stack.empty()) {
        int current = stack.top();
        stack.pop();
        for (int next : adj[current]) {
            if (visited[next] == 0) {
                stack.push(next);
                visited[next] = -visited[current];
            } else if (visited[next] == visited[current]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int testcases;
    std::cin >> testcases;
    for (int i = 0; i < testcases; ++i) {
        int V, E;
        std::cin >> V >> E;
        adj.assign(V + 1, std::vector<int>());
        visited.assign(V + 1, 0);

        for (int j = 0; j < E; ++j) {
            int from, to;
            std::cin >> from >> to;
            adj[from].push_back(to);
            adj[to].push_back(from);
        }

        bool isBipartite = true;
        for (int j = 1; j <= V; ++j) {
            if (visited[j] == 0) {
                if (!dfs(j)) {
                    isBipartite = false;
                    break;
                }
            }
        }
        std::cout << (isBipartite ? "YES" : "NO") << std::endl;
    }
    return 0;
}
