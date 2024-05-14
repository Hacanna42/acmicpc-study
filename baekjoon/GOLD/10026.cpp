// 백준: 적록색약
// https://www.acmicpc.net/problem/10026
// 2024-05-14
// 다음부턴 BFS를 함수로 빼자

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<vector<char>> map(N, vector<char>(N));
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            cin >> map[r][c];
        }
    }

    int loop = 2;
    int normal_count = 0;
    int blind_count = 0;
    while (loop--) {
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        queue<pair<int, int>> q; // (r, c)
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                if (!visited[r][c]) { // 방문하지 않았다면
                    if (loop == 1)
                        ++normal_count;
                    else
                        ++blind_count;
                    visited[r][c] = true;
                    char cur_color = map[r][c];
                    q.push({r, c});
                    while (!q.empty()) {
                        int cur_r = q.front().first;
                        int cur_c = q.front().second;
                        q.pop();
                        for (int i = 0; i < 4; ++i) {
                            int next_r = cur_r + dr[i];
                            int next_c = cur_c + dc[i];
                            if (next_r >= 0 && next_c >= 0 && next_r < N && next_c < N && !visited[next_r][next_c]) { // VALID CHECK
                                if (loop == 1) {                                                                      // 일반인 검사
                                    if (map[next_r][next_c] == cur_color) {
                                        q.push({next_r, next_c});
                                        visited[next_r][next_c] = true; // 방문 체크는 큐를 넣을 때 해야 함 (효율성)
                                    }
                                } else if (loop == 0) {                                                 // 적록색약 검사
                                    if (cur_color == 'R' || cur_color == 'G') {                         // 적 or 녹이라면
                                        if (map[next_r][next_c] == 'R' || map[next_r][next_c] == 'G') { // 둘 중 하나여도
                                            q.push({next_r, next_c});
                                            visited[next_r][next_c] = true;
                                        }
                                    } else { // 블루라면
                                        if (map[next_r][next_c] == cur_color) {
                                            q.push({next_r, next_c});
                                            visited[next_r][next_c] = true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << normal_count << " " << blind_count;
    return 0;
}