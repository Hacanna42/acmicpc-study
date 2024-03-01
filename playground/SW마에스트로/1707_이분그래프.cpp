#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> adj;
bool isBipartite;

void dfs(int node, vector<int> &visited, int color) {
    if (!isBipartite)
        return;
    visited[node] = color;
    for (const auto &next : adj[node]) {
        if (visited[next] == -1) {
            dfs(next, visited, 1 - color);
        } else if (visited[next] == color) {
            isBipartite = false;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int TC;
    cin >> TC;
    while (TC--) {
        int V, E;
        cin >> V >> E;
        adj.assign(V + 1, vector<int>());
        vector<int> visited(V + 1, -1);
        isBipartite = true;
        for (int i = 0; i < E; ++i) {
            int from, to;
            cin >> from >> to;
            adj[from].push_back(to);
            adj[to].push_back(from);
        }

        for (int i = 1; i <= V && isBipartite; ++i) {
            if (visited[i] == -1) {
                dfs(i, visited, 0); // 방문하지 않은 정점에 대해 DFS 실행
            }
        }

        cout << (isBipartite ? "YES\n" : "NO\n");
    }
    return 0;
}