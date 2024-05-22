// 백준: 최소 비용 구하기
// https://www.acmicpc.net/problem/1916
// 2024-05-22

/*
다익스트라는 방문 배열(visited)을 사용하면 안된다.
if (cur_weight > dist[cur_node]) 로 처리하자.
*/

#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define INF (~0U >> 2)
using namespace std;

int N, M; // 도시 개수 N, 버스 개수 M

int dijkstra(int start, int dest, vector<vector<pair<int, int>>> &adj) {
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 최단 거리 탐색을 위한 우선순위 큐
    dist[start] = 0;                                                                    // 출발 지점
    pq.push({0, start});                                                                // 가중치, 노드

    while (!pq.empty()) {
        int cur_node = pq.top().second;
        int cur_weight = pq.top().first;
        pq.pop();

        if (cur_weight > dist[cur_node])
            continue;

        for (const auto &next : adj[cur_node]) {
            int next_node = next.second;
            int weight = next.first;
            int next_weight = cur_weight + weight;
            if (next_weight < dist[next_node]) {
                dist[next_node] = next_weight;
                pq.push({next_weight, next_node});
            }
        }
    }

    return dist[dest];
}

int main() {
    cin >> N >> M;
    vector<vector<pair<int, int>>> adj(N + 1, vector<pair<int, int>>()); // 가중치, 노드
    for (int i = 0; i < M; ++i) {
        int start_node, end_node, weight;
        cin >> start_node >> end_node >> weight;
        adj[start_node].push_back({weight, end_node});
    }
    int start, dest;
    cin >> start >> dest;

    cout << dijkstra(start, dest, adj);
    return 0;
}