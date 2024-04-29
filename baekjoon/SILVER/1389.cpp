// 백준: 케빈 베이컨의 6단계 법칙
// https://www.acmicpc.net/problem/1389
// 2024-04-29

/*
1. 이중 반복문으로 from -> to 지정
2. BFS로 from에서 부터 모든 to까지의 거리 구하기
*/

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M; // 유저 수 N, 관계 수 M.
    cin >> N >> M;
    vector<vector<int>> adj(N + 1, vector<int>());
    for (int i = 0; i < M; ++i) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    int known_min_man = -1;
    int known_min_dist = (~0U >> 2);

    for (int from = 1; from <= N; ++from) { // 케빈 베이컨 조사 당할 사람
        int sum_dist = 0;
        for (int to = 1; to <= N; ++to) { // from -> to 거리 조사
            if (to == from)
                continue; // 자기자신 스킵

            // BFS 시작 (from -> to)
            queue<pair<int, int>> q; // node,  t
            vector<int> visited(N + 1, false);
            q.push({from, 0});
            visited[from] = true; // 시작 방문 체크
            while (!q.empty()) {
                int cur_node = q.front().first;
                int cur_time = q.front().second;
                q.pop();

                // 체크
                if (cur_node == to) {
                    sum_dist += cur_time; // 거리합에 가중치를 누적시키고
                    break;                // 종료
                }

                for (int &next : adj[cur_node]) {
                    if (!visited[next]) {
                        visited[next] = true; // 방문 표시
                        q.push({next, cur_time + 1});
                    }
                }
            }
        }

        // from에 대한 케빈 베이컨 조사 끝
        if (sum_dist < known_min_dist) {
            known_min_dist = sum_dist;
            known_min_man = from;
        }
    }

    cout << known_min_man;
    return 0;
}