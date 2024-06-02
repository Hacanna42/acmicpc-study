// 백준: 서강그라운드
// https://www.acmicpc.net/problem/14938
// 2024-05-31

/*
모든 노드에 대해서 다익스트라를 하고, 거리가 m 이내인 아이템 값 합
*/

#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define INF (~0U >> 2)
using namespace std;

int n, m, r; // 지역의 개수 n, 예은이의 수색 범위 m, 길의 개수 r
vector<int> dijkstra(int start, vector<vector<pair<int, int>>> &adj) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, INF);
    dist[start] = 0; // 시작 지점 0으로
    pq.push({0, start});

    while (!pq.empty()) {
        int cur_node = pq.top().second;
        int cur_weight = pq.top().first;
        pq.pop();

        if (cur_weight > dist[cur_node])
            continue; // 알려진 최단 거리보다 길면 스킵

        for (const auto &next : adj[cur_node]) {
            int next_node = next.second;
            int weight = next.first;
            int new_weight = cur_weight + weight;
            if (new_weight < dist[next_node]) {
                dist[next_node] = new_weight;
                pq.push({new_weight, next_node});
            }
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> r;              // 지역의 개수 n, 예은이의 수색 범위 m, 길의 개수 r
    vector<int> item_info(n + 1, 0); // 노드별 아이템 개수 정보
    for (int i = 1; i <= n; ++i) {
        cin >> item_info[i];
    }

    vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>()); // 가중치, 노드
    for (int i = 0; i < r; ++i) {                                        // 간선 입력받기
        int from, to, weight;
        cin >> from >> to >> weight;
        adj[from].push_back({weight, to});
        adj[to].push_back({weight, from});
    }

    // 각 노드에 대해서 다익스트라 탐색, 가중치가 m 이하인 모든 지역의 아이템 수 합 얻기
    int max_sum = 0;
    for (int cur_node = 1; cur_node <= n; ++cur_node) {
        vector<int> dist = dijkstra(cur_node, adj);
        int item_sum = 0;                             // 얻을 수 있는 아이템 합계
        for (int target = 1; target <= n; ++target) { // cur_node로부터 거리가 m 이하인 노드 탐색
            if (dist[target] <= m) {                  // 거리가 m 이내라면
                item_sum += item_info[target];
            }
        }
        max_sum = max(max_sum, item_sum);
    }

    cout << max_sum;
    return 0;
}