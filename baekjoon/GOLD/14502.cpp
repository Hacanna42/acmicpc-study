// 백준: 연구소
// https://www.acmicpc.net/problem/14502
// 2024-05-29

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M;         // 맵 사이즈
int wall_cnt = 0; // 벽 개수
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int known_least_virus_cnt = (~0U >> 2);

void virus_simulation(vector<vector<int>> &map, vector<pair<int, int>> &virus_pos) {
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    int virus_cnt = 0;
    for (const auto &pos : virus_pos) {
        // 바이러스 위치
        int r = pos.first;
        int c = pos.second;

        queue<pair<int, int>> q;
        q.push({r, c});
        visited[r][c] = true;
        while (!q.empty()) {
            // 전파
            int cur_r = q.front().first;
            int cur_c = q.front().second;
            q.pop();

            virus_cnt++;

            if (virus_cnt > known_least_virus_cnt) // 이전 최적해를 이미 넘어섰다면 (가지치기)
                return;

            for (int i = 0; i < 4; ++i) {
                int next_r = cur_r + dr[i];
                int next_c = cur_c + dc[i];
                // VALID CHECK : 경계, 빈칸에만 전파 허용
                if (next_r >= 0 && next_c >= 0 && next_r < N && next_c < M && !visited[next_r][next_c] && map[next_r][next_c] == 0) {
                    q.push({next_r, next_c});
                    visited[next_r][next_c] = true;
                }
            }
        }
    }

    if (virus_cnt < known_least_virus_cnt) // 최솟값 갱신
        known_least_virus_cnt = virus_cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    // 0: 빈칸
    // 1: 벽
    // 2: 바이러스
    vector<vector<int>> map(N, vector<int>(M));
    vector<pair<int, int>> virus_pos;
    vector<pair<int, int>> possible_place;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            cin >> map[r][c];
            if (map[r][c] == 1)
                wall_cnt++; // 최적화를 위해 벽 개수 세놓기
            else if (map[r][c] == 2)
                virus_pos.push_back({r, c});
            else if (map[r][c] == 0)
                possible_place.push_back({r, c});
        }
    }

    // 조합 완전 탐색
    int SIZE = possible_place.size();
    for (int i = 0; i < SIZE; ++i) {
        for (int j = i + 1; j < SIZE; ++j) {
            for (int k = j + 1; k < SIZE; ++k) {
                // 맵 수정
                map[possible_place[i].first][possible_place[i].second] = 1;
                map[possible_place[j].first][possible_place[j].second] = 1;
                map[possible_place[k].first][possible_place[k].second] = 1;

                virus_simulation(map, virus_pos);

                // 맵 수정
                map[possible_place[i].first][possible_place[i].second] = 0;
                map[possible_place[j].first][possible_place[j].second] = 0;
                map[possible_place[k].first][possible_place[k].second] = 0;
            }
        }
    }

    cout << N * M - known_least_virus_cnt - wall_cnt - 3;
    return 0;
}