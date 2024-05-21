// 백준: 파티
// https://www.acmicpc.net/problem/1238
// 2024-05-19

#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define INF (~0U >> 2)
using namespace std;

int N, M, X; // 마을(학생) 수 N, 단방향 도로 M, 파티 마을 X

vector<int> dijkstra(int start_node, vector<vector<pair<int, int>>> &adj) { // 다익스트라 알고리즘으로 최단 거리를 탐색한다. 가중치가 동일하지 않으므로 BFS를 사용할 수 없다.
    vector<int> dist(N + 1, INF);
    dist[start_node] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 거리, 정점
    pq.push({0, start_node});

    while (!pq.empty()) {
        int cur_node = pq.top().second;
        int cur_dist = pq.top().first;
        pq.pop();

        if (cur_dist > dist[cur_node])
            continue; // 이미 처리된 노드 무시

        for (const auto &next : adj[cur_node]) {
            int next_node = next.first;
            int next_dist = cur_dist + next.second;
            if (dist[next_node] > next_dist) {
                dist[next_node] = next_dist;
                pq.push({next_dist, next_node});
            }
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> X;
    vector<vector<pair<int, int>>> adj(N + 1, vector<pair<int, int>>());
    for (int i = 0; i < M; ++i) {
        int start_node, end_node, v;
        cin >> start_node >> end_node >> v;
        adj[start_node].push_back({end_node, v});
    }

    // 먼저 파티 마을에서 각 노드까지 얼마나 걸리는 지 저장
    vector<int> dist_sum = dijkstra(X, adj);

    // 그런 다음, 각 노드에서 파티 마을까지의 최소 거리를 합산
    for (int i = 1; i <= N; ++i) {
        if (i == X)
            continue; // 파티 마을 무시
        dist_sum[i] += dijkstra(i, adj)[X];
    }

    cout << *max_element(dist_sum.begin() + 1, dist_sum.end());
    return 0;
}