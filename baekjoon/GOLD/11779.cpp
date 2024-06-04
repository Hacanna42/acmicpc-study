// 백준: 최소비용 구하기 2
// https://www.acmicpc.net/problem/11779
// 2024-06-04
// 다익스트라 최단거리 역추적

#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
#define INF (~0U >> 2)

int n, m;         // 도시 개수 n, 버스 개수 m
vector<int> path; // 역추적 경로 저장

int dijkstra(int start, int target, vector<vector<pair<int, int>>> &adj) {
    vector<int> dist(n + 1, INF);
    dist[start] = 0; // 시작 노드 0으로
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int cur_node = pq.top().second;
        int cur_weight = pq.top().first;
        pq.pop();

        if (cur_weight > dist[cur_node])
            continue; // 이미 알려진 최단 거리보다 길면 스킵

        for (const auto &next : adj[cur_node]) {
            int new_weight = cur_weight + next.first;
            if (new_weight < dist[next.second]) {
                dist[next.second] = new_weight;
                pq.push({new_weight, next.second});
                path[next.second] = cur_node; // 역추적 경로 설정
            }
        }
    }

    return dist[target];
}

void printPath(int start, int target) {
    vector<int> result;
    for (int at = target; at != -1; at = path[at])
        result.push_back(at);
    reverse(result.begin(), result.end());
    cout << result.size() << "\n";
    for (const auto &next : result)
        cout << next << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;          // 도시 개수 n, 버스 개수 m
    path.assign(n + 1, -1); // 역추적 경로 -1로 초기화
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        adj[from].push_back({weight, to});
    }
    int start, target;
    cin >> start >> target;
    cout << dijkstra(start, target, adj) << "\n";
    printPath(start, target);
    return 0;
}