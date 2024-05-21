// 백준: 웜홀
// https://www.acmicpc.net/problem/1865
// 2024-05-19

/* 벨만-포드 알고리즘 기초 문제
다익스트라와 유사하지만, 인접한 정점부터 탐색하는 게 아니라 그냥 싸그리 탐색 해도 됨.
주의: 모든 지점이 연결 되어있다는 보장이 없다. 연결 그래프라면 아무 곳이나 탐색해도 음의 순환이 발견되겠지만. 그게 아니다.
만약 dist[i] = INF 일때의 갱신을 허용하지 않는다면. 시작 노드와 연결이 끊겨 있는 그래프가 갱신되지 않아서 음의 사이클을 발견 못 할수도 있다.
따라서, INF의 값이 오버플로우가 나지 않게 타협하고, INF 일때도 음수 가중치를 만나면 갱신이 될 수 있도록 한다. 이렇게 해야 임의의 노드에서 1번 탐색해도 음의 사이클을 탐지할 수 있다.
*/

#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
#define INF (~0U >> 2)
using namespace std;

vector<int> dist;

bool bellmanFord(int start, int V, vector<tuple<int, int, int>> &edges) {
    dist.assign(V + 1, INF);
    dist[start] = 0; // 시작 지점 (이건 이제 아무 의미가 없다)

    for (int i = 0; i < V - 1; ++i) { // V - 1번 완화(Relaxation)
        for (const auto &edge : edges) {
            int s, e, t;
            tie(s, e, t) = edge;

            if (dist[s] + t < dist[e]) {
                dist[e] = dist[s] + t;
            }
        }
    }

    // 음의 사이클 확인
    for (const auto &edge : edges) {
        int s, e, t;
        tie(s, e, t) = edge;

        if (dist[s] != INF && dist[s] + t < dist[e])
            return true; // 음의 사이클 있음
    }

    return false; // 음의 사이클 없음
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int TC;
    cin >> TC;
    while (TC--) {
        int N; // 지점의 수
        int M; // 도로 개수
        int W; // 웜홀 개수 (음수 가중치)
        cin >> N >> M >> W;
        vector<tuple<int, int, int>> edges;

        // 주의: (본문) 도로는 방향이 없으며, 웜홀은 방향이 있다.
        for (int i = 0; i < M; ++i) {
            int S, E, T; // 시작 지점, 도착 지점, 가중치
            cin >> S >> E >> T;
            edges.push_back(make_tuple(S, E, T));
            edges.push_back(make_tuple(E, S, T));
        }
        for (int i = 0; i < W; ++i) {
            int S, E, T; // 가중치 *-1 유의
            cin >> S >> E >> T;
            edges.push_back(make_tuple(S, E, T * -1));
        }

        if (bellmanFord(1, N, edges))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}