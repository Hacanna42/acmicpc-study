#include <algorithm>
#include <iostream>
#include <queue>
#include <random>
#include <stack>
#include <vector>
using namespace std;

vector<vector<int>> adj;

void recursiveDFS(int current, vector<bool> &visited, vector<int> &route) {
    visited[current] = true;
    route.push_back(current);

    for (const auto &next : adj[current]) {
        if (!visited[next]) { // 방문 X
            recursiveDFS(next, visited, route);
        }
    }
}

int main() {
    int N, M, V;
    cin >> N >> M >> V;
    adj.assign(N + 1, vector<int>());

    for (int i = 0; i < M; ++i) {
        int to, from;
        cin >> to >> from;
        adj[to].push_back(from);
        adj[from].push_back(to);
    }

    for (int i = 1; i <= N; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }

    // 재귀 DFS
    vector<bool> visited_dfs_recursive(N + 1, false);
    vector<int> route_dfs_recursive;
    recursiveDFS(V, visited_dfs_recursive, route_dfs_recursive);

    // 스택 DFS - (정점이 작은 순서대로 방문할 수 없다. 인접 정점을 역순으로 탐색하면 가능하다. 재귀 DFS는 첫번째 탐색된 노드.
    // 즉 왼쪽 분기부터 타고 내려가지만 스택은 현재 분기에서 마지막으로 탐색된 노드. 즉 오른쪽 분기부터 타고 내려간다.)
    vector<bool> visited_dfs_stack(N + 1, false);
    vector<int> route_dfs_stack;
    stack<int> s;
    s.push(V);

    while (!s.empty()) {
        int cur_v = s.top();
        s.pop();

        if (!visited_dfs_stack[cur_v]) {
            visited_dfs_stack[cur_v] = true; // 방문 처리
            route_dfs_stack.push_back(cur_v);

            for (auto it = adj[cur_v].rbegin(); it != adj[cur_v].rend(); ++it) {
                if (!visited_dfs_stack[*it]) {
                    s.push(*it);
                }
            }
        }
    }

    // 큐 BFS
    vector<bool> visited_bfs(N + 1, false);
    vector<int> route_bfs;
    queue<int> q;
    q.push(V);
    while (!q.empty()) {
        int cur_v = q.front();
        q.pop();

        if (!visited_bfs[cur_v]) { // 방문하지 않았다면
            visited_bfs[cur_v] = true;
            route_bfs.push_back(cur_v);

            for (const auto &next : adj[cur_v]) {
                if (!visited_bfs[next]) {
                    q.push(next);
                }
            }
        }
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution dis(0.5);

    bool fun = dis(gen);

    if (fun) {
        for (auto &iter : route_dfs_recursive) {
            cout << iter << " ";
        }
    } else {
        for (auto &iter : route_dfs_stack) {
            cout << iter << " ";
        }
    }

    cout << "\n";
    for (auto &iter : route_bfs) {
        cout << iter << " ";
    }

    return 0;
}