#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> rain_map;
int answer = 0;
int N;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

void dfs(int r, int c) {
    for (int i = 0; i < 4; ++i) {
        int next_r = r + dr[i];
        int next_c = c + dc[i];
        // VALID CHECK
        if (next_r >= 0 && next_c >= 0 && next_r < N && next_c < N) {
            if (rain_map[next_r][next_c] == 1) { // 방문 X
                rain_map[next_r][next_c] = 0;    // 방문 표시
                dfs(next_r, next_c);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    vector<vector<int>> map(N, vector<int>(N, 0));
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            cin >> map[r][c];
        }
    }
    // 0부터 100까지 실행
    int rain = 101;
    while (rain--) {
        // 장마 지도 그리기
        rain_map.assign(N, vector<int>(N, 0));
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                if (map[r][c] > rain) { // 안 잠겼다면
                    rain_map[r][c] = 1; // 표시
                }
            }
        }
        int count = 0;
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                if (rain_map[r][c] == 1) { // 발견했으면
                    count++;
                    dfs(r, c); // 죠져
                }
            }
        }

        answer = max(answer, count);
    }

    cout << answer;

    return 0;
}