// 백준: 치킨 배달
// https://www.acmicpc.net/problem/15686
// 2024-05-22

/*
가지치기: 알려진 최솟값보다 높은 값이 갱신되면 중단
*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int N, M; // N*N 크기의 도시, 폐업시키지 않을 치킨 집 M
vector<vector<pair<int, int>>> paths;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

void getAllCombination(vector<pair<int, int>> &path, vector<pair<int, int>> &chicken_markets, int start) {
    if (path.size() == M) {
        paths.push_back(path);
        return;
    }

    int SIZE = chicken_markets.size();
    for (int i = start; i < SIZE; ++i) {
        int cur_r = chicken_markets[i].first;
        int cur_c = chicken_markets[i].second;
        path.push_back({cur_r, cur_c});
        getAllCombination(path, chicken_markets, i + 1);
        path.pop_back();
    }
}

// BFS 탐색을 사용했는데, 맨해튼 거리를 사용해서 (절댓값 좌표의 차이) TLE를 막자
// int getNearestChicken(int start_r, int start_c, vector<vector<int>> &map) {
//     vector<vector<bool>> visited(N, vector<bool>(N, false));
//     queue<pair<int, pair<int, int>>> q;
//     q.push({0, {start_r, start_c}});
//     while (!q.empty()) {
//         int cur_r = q.front().second.first;
//         int cur_c = q.front().second.second;
//         int cur_weight = q.front().first;
//         q.pop();

//         if (map[cur_r][cur_c] == 2) { // 치킨집이라면
//             return cur_weight;
//         }

//         for (int i = 0; i < 4; ++i) {
//             int next_r = cur_r + dr[i];
//             int next_c = cur_c + dc[i];
//             if (next_r >= 0 && next_c >= 0 && next_r < N && next_c < N && !visited[next_r][next_c]) {
//                 visited[next_r][next_c] = true;
//                 q.push({cur_weight + 1, {next_r, next_c}});
//             }
//         }
//     }
//     return -1; // 찾지 못함
// }

int getNearestChicken(vector<vector<int>> &map) {
    int known_shortest_dist = (~0U >> 2);
    for (const auto &path : paths) {
        int dist_sum = 0;
        bool stop = false;
        for (int r = 0; r < N && !stop; ++r) {
            for (int c = 0; c < N && !stop; ++c) {
                if (map[r][c] == 1) { // 집이라면
                    int cur_shortest_dist = (~0U >> 2);
                    for (const auto &next : path) {
                        int cur_chicken_r = next.first;
                        int cur_chicken_c = next.second;
                        // |r1 - r2| + |c1 + c2|
                        cur_shortest_dist = min(cur_shortest_dist, abs(r - cur_chicken_r) + abs(c - cur_chicken_c));
                    }
                    dist_sum += cur_shortest_dist;
                    if (dist_sum >= known_shortest_dist) {
                        stop = true;
                        break;
                    }
                }
            }
        }
        if (!stop)
            known_shortest_dist = min(known_shortest_dist, dist_sum);
    }
    return known_shortest_dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    vector<vector<int>> map(N, vector<int>(N));
    vector<pair<int, int>> chicken_markets;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            cin >> map[r][c];
            if (map[r][c] == 2) { // 치킨 집 정보 저장
                chicken_markets.push_back({r, c});
                map[r][c] = 0; // 빈칸으로 되돌려놓기
            }
        }
    }

    vector<pair<int, int>> path;
    getAllCombination(path, chicken_markets, 0);
    cout << getNearestChicken(map);
    return 0;
}