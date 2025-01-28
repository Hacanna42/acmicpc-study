// 백준: 특정한 최단 경로
// https://www.acmicpc.net/problem/1504
// 2024-01-26

/*
from -> v1 -> v2 -> to 보다 from -> v2 -> v1 -> to 가 빠를 수 있으므로
두가지 경우를 모두 고려한다.
*/

#include <limits.h>

#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

std::vector<std::vector<std::pair<int, int>>> adj; // PAIR = 정점, 거리
std::vector<int> dist;                             // 각 정점까지의 최단거리 Memoization
int v1, v2;
int V, E; // 정점의 개수 N, 간선의 개수 E

int dijkstra(int start, int end) {
    std::fill(dist.begin(), dist.end(), INT_MAX);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int current_distance = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (current_distance > dist[current])
            continue;

        for (const std::pair<int, int> &pair : adj[current]) {
            int next = pair.first;
            int next_distance = current_distance + pair.second;
            if (next_distance < dist[next]) {
                dist[next] = next_distance;
                pq.push({next_distance, next});
            }
        }
    }

    return (dist[end] == INT_MAX) ? -1 : dist[end];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> V >> E;
    adj.assign(V + 1, std::vector<std::pair<int, int>>());
    dist.assign(V + 1, INT_MAX);
    for (int i = 0; i < E; ++i) {
        int from, to, w;
        std::cin >> from >> to >> w;
        adj[from].push_back({to, w});
        adj[to].push_back({from, w}); // 양방향 간선 추가
    }
    std::cin >> v1 >> v2; // 반드시 거쳐야 하는 정점 (from -> v1 -> v2 -> to 가
                          // 빠른지, from -> v2 -> v1 -> to가 빠른지 모른다)

    int route1_part1 = dijkstra(1, v1);
    int route1_part2 = dijkstra(v1, v2);
    int route1_part3 = dijkstra(v2, V);
    int route1 = (route1_part1 == -1 || route1_part2 == -1 || route1_part3 == -1) ? -1 : route1_part1 + route1_part2 + route1_part3;

    int route2_part1 = dijkstra(1, v2);
    int route2_part2 = dijkstra(v2, v1);
    int route2_part3 = dijkstra(v1, V);
    int route2 = (route2_part1 == -1 || route2_part2 == -1 || route2_part3 == -1) ? -1 : route2_part1 + route2_part2 + route2_part3;

    if (route1 == -1 && route2 == -1) {
        std::cout << -1 << std::endl;
    } else if (route1 == -1) {
        std::cout << route2 << std::endl;
    } else if (route2 == -1) {
        std::cout << route1 << std::endl;
    } else {
        std::cout << std::min(route1, route2) << std::endl;
    }

    return 0;
}