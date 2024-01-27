// 백준: 미확인 도착지
// https://www.acmicpc.net/problem/9370
// 2024-01-27

/* 이 문제에서 교차로 개수라는 것은 결국엔 정점의 개수 V
-
다익스트라 알고리즘은 최단 거리를 구할 순 있지만, 최단 거리의 경로는 구할 수
없다. 하지만 문제에서: "이 도로는 목적지 후보들 중 적어도 1개로 향하는 최단
경로의 일부이다." 따라서, 먼저 시작점을 기준으로 모든 정점에 대한 최단 거리를
다익스트라를 통해 구하고, 후각 간선을 통해 각 목적지로 가는 최단 거리를 구하고,
거리가 일치하는 목적지를 후보라고 생각할 수 있을 것이다.

처음엔 시작 지점(s)로부터 후보 목적지들까지의 거리를 구하고.
각 후보 목적지들을 g -> h를 경유해(혹은 반대로) 도착하는 최단 거리를 구해야
한다.

따라서 함수가 인자로 시작 지점과 끝 지점을 받고, 최단 거리를 반환하도록 해야할
듯.

주의: priority_queue는 pair의 첫번째 요소를 기준으로 정렬하기 때문에, 누적거리를
.first에 둬야함.
 */

#include <limits.h>

#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int n, m, t;  // 교차로 개수, 도로 개수, 목적지 후보 개수
int s, g, h;  // 듀오 출발지, 후각 간선 2개

std::vector<std::vector<std::pair<int, int> > >
    adj;  // PAIR = 거리 | 연결된 정점

std::vector<bool> visited;

std::vector<int> dist;

int dijkstra(int start, int end) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >,
                        std::greater<std::pair<int, int> > >
        pq;  // PAIR = 현재 노드까지의 누적된 최단 거리 | 정점 인덱스
    dist.clear();
    visited.clear();
    dist.resize(n + 1, INT_MAX);
    visited.resize(n + 1, false);

    dist[start] = 0;  // 시작 지점부터 시작 지점까지의 거리는 0
    pq.push({0, start});

    while (!pq.empty()) {
        int current_pos = pq.top().second;
        int current_distance = pq.top().first;
        pq.pop();

        if (visited[current_pos]) continue;
        visited[current_pos] = true;

        // 인접한 노드들의 거리를 검사하고 업데이트 로직
        for (const auto& pair : adj[current_pos]) {
            int next_pos = pair.second;
            int next_distance = current_distance + pair.first;
            if (dist[next_pos] > next_distance) {
                dist[next_pos] = next_distance;
                pq.push({next_distance, next_pos});
            }
        }
    }

    if (dist[end] == INT_MAX) return -1;

    return dist[end];
}

int main() {
    int T;
    std::cin >> T;

    for (int tc = 0; tc < T; ++tc) {
        std::cin >> n >> m >> t >> s >> g >> h;
        // 자료 초기화
        adj.clear();
        adj.resize(n + 1);
        // dist.resize(n + 1, INT_MAX);
        // visited.resize(n + 1, false);

        for (int i = 0; i < m; ++i) {
            int a, b, d;  // a와 b사이의 양방향 도로 길이 d
            std::cin >> a >> b >> d;
            // adj 정보 추가
            adj[a].push_back({d, b});
            adj[b].push_back({d, a});
        }

        std::vector<int> candidates;

        for (int i = 0; i < t; ++i) {
            int tt;
            std::cin >> tt;
            // s -> g -> h -> tt 와 s -> h -> g -> tt 고려
            int d1 = dijkstra(s, g);
            int d2 = dijkstra(g, h);
            int d3 = dijkstra(h, tt);

            int d4 = dijkstra(s, h);
            int d5 = dijkstra(h, g);
            int d6 = dijkstra(g, tt);

            // 각 경로중 하나라도 불가능하면...을 처리하기 위해
            int final_dist1 = INT_MAX;
            int final_dist2 = INT_MAX;

            if (d1 != -1 && d2 != -1 && d3 != -1) final_dist1 = d1 + d2 + d3;
            if (d4 != -1 && d5 != -1 && d6 != -1) final_dist2 = d4 + d5 + d6;

            int shortest = INT_MAX;
            if (final_dist1 != INT_MAX && final_dist2 != INT_MAX) {
                // 둘 다 유효한 경로면, 최단 거리를 최종 경로로 설정.
                if (final_dist1 > final_dist2)
                    shortest = final_dist2;
                else
                    shortest = final_dist1;
            } else if (final_dist1 != INT_MAX) {  // 하나만 유효하다면..
                shortest = final_dist1;
            } else if (final_dist2 != INT_MAX) {
                shortest = final_dist2;
            }

            // 변수 shortest = 각 후보 목적지에 대해 g, h를 거친 최단경로
            int temp = dijkstra(s, tt);
            if (temp != INT_MAX && shortest != INT_MAX && shortest == temp)
                candidates.push_back(tt);
        }

        // 오름차순으로 정렬 후 후보를 출력
        std::sort(candidates.begin(), candidates.end());

        for (const auto& iter : candidates) {
            std::cout << iter << " ";
        }
        std::cout << "\n";
    }

    return 0;
}