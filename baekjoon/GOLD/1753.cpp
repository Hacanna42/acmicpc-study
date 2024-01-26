// 백준: 최단경로
// https://www.acmicpc.net/problem/1753
// 2024-01-26
// 다익스트라 알고리즘 입문 문제

#include <limits.h>

#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int V, E, K;
std::vector<int> dist;
std::vector<bool> visited;
std::vector<std::vector<std::pair<int, int> > > adj;

/*
Ignite. 시작 노드와 직접적으로 연결된 모든 정점들의 거리를 비교해서 업데이트
하고, 시작 노드를 방문 표시
1. 방문한 정점들과 연결되어있는 정점들 중, 비용이 가장 적게 드는 정점을
방문표시.
2. 1번 과정에서 갱신될 수 있는 정점의 거리를 갱신
3. 1 ~ 2 반복
*/

void dijkstra(int start) {
    // 점화
    dist[K] = 0;  // 시작 정점의 거리는 0

    // 이거 어차피 아래 while에서 처리됨 **
    // // 시작 노드와 직접적으로 연결된 모든 정점의 거리를 dist에 업데이트
    // for (const std::pair<int, int>& pair : adj[K]) {
    //     dist[pair.first] = pair.second;
    // }
    // // 그리고, 시작 노드를 방문 표시
    // visited[K] = true;

    // 단계 시작
    // 현재까지 알려진 최단 거리 정점을 효율적으로 뽑기 위해 priority_queue를
    // 사용함.
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >,
                        std::greater<std::pair<int, int> > >
        pq;  // pair: 거리, 정점 순서

    pq.push({0, start});

    while (!pq.empty()) {
        int distance = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (visited[current]) continue;  // 방문했다면, 스킵
        visited[current] = true;         // 방문 표시
        for (const std::pair<int, int>& pair :
             adj[current]) {  // pair: 정점, 거리 순서
            int next = pair.first;
            int nextDistance = distance + pair.second;
            if (nextDistance < dist[next]) {
                dist[next] = nextDistance;
                pq.push({nextDistance, next});
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> V >> E >> K;
    dist.assign(V + 1, INT_MAX);
    visited.assign(V + 1, false);
    adj.assign(V + 1, std::vector<std::pair<int, int> >());
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    dijkstra(K);

    for (int i = 1; i <= V; ++i) {
        if (dist[i] == INT_MAX)
            std::cout << "INF"
                      << "\n";
        else
            std::cout << dist[i] << "\n";
    }
    return 0;
}