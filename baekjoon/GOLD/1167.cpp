// 백준: 트리의 지름
// https://www.acmicpc.net/problem/1167
// 2024-05-19

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
vector<vector<pair<int, int>>> adj;
int V;

pair<int, int> bfs(int start) {
    pair<int, int> farthest_node = {0, 0};
    queue<pair<int, int>> q;
    vector<bool> visited(V + 1, false);
    q.push({0, start}); // 가중치, 노드
    visited[start] = true;

    while (!q.empty()) {
        int cur_node = q.front().second;
        int cur_weight = q.front().first;
        q.pop();

        if (farthest_node.first < cur_weight)
            farthest_node = {cur_weight, cur_node};

        for (const auto &next : adj[cur_node]) {
            int next_node = next.second;
            int weight = next.first;
            if (!visited[next_node]) {
                q.push({cur_weight + weight, next_node});
                visited[next_node] = true;
            }
        }
    }

    return farthest_node;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> V;
    adj.assign(V + 1, vector<pair<int, int>>()); // 거리, 정점
    for (int i = 0; i < V; ++i) {
        int cur_node;
        cin >> cur_node;
        while (true) {
            int dest_node, value;
            cin >> dest_node;
            if (dest_node == -1)
                break;
            cin >> value;
            adj[cur_node].push_back({value, dest_node});
            adj[dest_node].push_back({value, cur_node}); // 양방향으로 추가
        }
    }

    // 임의의 점에서 가장 먼 노드 A를 구한다.
    // 노드 A에서 가장 먼 노드 B를 구한다.
    // A -> B가 트리의 지름
    pair<int, int> farthest_node = bfs(1);
    cout << bfs(farthest_node.second).first;
    return 0;
}