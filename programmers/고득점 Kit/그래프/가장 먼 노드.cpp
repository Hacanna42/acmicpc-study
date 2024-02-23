#include <algorithm>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> adj(n + 1, vector<int>());

    // 간선 정보 추가
    for (const auto e : edge) {
        int start = e[0];
        int end = e[1];
        adj[start].push_back(end);
        adj[end].push_back(start);
    }

    // BFS로 탐색
    queue<pair<int, int>> q;          // 노드, 거리
    q.push({1, 0});                   // 1번 노드, 거리 0
    vector<bool> visited(n + 1);      // 방문 배열
    vector<int> node_distance(n + 1); // 노드별 거리 저장 배열

    visited[1] = true;

    while (!q.empty()) {
        int current_node = q.front().first;
        int current_weight = q.front().second;
        q.pop();

        // 거리 저장
        node_distance[current_node] = current_weight;

        for (const auto &next : adj[current_node]) {
            if (!visited[next]) {
                q.push({next, current_weight + 1});
                visited[next] = true;
            }
        }
    }

    // 제일 먼 노드
    int max_dist = *max_element(node_distance.begin(), node_distance.end());
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (node_distance[i] == max_dist) {
            ++count;
        }
    }
    return count;
}