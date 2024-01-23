#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

std::vector<int> adj[1001];
std::vector<bool> visited_dfs(1001, false);
std::vector<bool> visited_bfs(1001, false);
std::vector<int> order_dfs;
std::vector<int> order_bfs;

void dfs(int start) {
    std::stack<int> stack;
    stack.push(start);
    while (!stack.empty()) {
        int current = stack.top();
        stack.pop();

        if (!visited_dfs[current]) {
            visited_dfs[current] = true;
            order_dfs.push_back(current);

            for (int i = adj[current].size() - 1; i >= 0; --i) {
                int next = adj[current][i];
                if (!visited_dfs[next]) {
                    stack.push(next);
                }
            }
        }
    }
}

void bfs(int start) {
    std::queue<int> queue;
    visited_bfs[start] = true;
    queue.push(start);
    while (!queue.empty()) {
        int current = queue.front();
        queue.pop();
        order_bfs.push_back(current);

        for (const int next : adj[current]) {
            if (!visited_bfs[next]) {
                queue.push(next);
                visited_bfs[next] = true;
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N, M, V;
    std::cin >> N >> M >> V;
    for (int i = 0; i < M; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // 양방향
    }

    for (int i = 1; i <= N; ++i) {
        std::sort(adj[i].begin(), adj[i].end());
    }

    dfs(V);
    bfs(V);

    for (const auto k : order_dfs) {
        std::cout << k << " ";
    }
    std::cout << "\n";
    for (const auto k : order_bfs) {
        std::cout << k << " ";
    }
}