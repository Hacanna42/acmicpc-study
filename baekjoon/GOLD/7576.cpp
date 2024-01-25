// 백준: 토마토
// https://www.acmicpc.net/problem/7576
// 2024-01-25

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

std::vector<std::vector<int> > matrix;
int M, N;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs() {
    std::queue<std::pair<std::pair<int, int>, int> > q;

    // 토마토 초기값을 큐에 넣기
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (matrix[i][j] == 1) {
                q.push({{j, i}, 0});
                // matrix[i][j] = true; ?이거 왜넣음
            }
        }
    }
    int answer_time = 0;
    while (!q.empty()) {
        int current_x = q.front().first.first;
        int current_y = q.front().first.second;
        int time = q.front().second;
        q.pop();
        answer_time = time;

        for (int i = 0; i < 4; ++i) {
            int next_x = current_x + dx[i];
            int next_y = current_y + dy[i];
            // valid check
            if (next_x >= 0 && next_y >= 0 && next_x < M && next_y < N) {
                if (matrix[next_y][next_x] == 0) {
                    q.push({{next_x, next_y}, time + 1});
                    matrix[next_y][next_x] = 1;
                }
            }
        }
    }
    // 다 익었는지 체크
    bool temp = true;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (matrix[i][j] == 0) {
                return -1;
            }
        }
    }
    return answer_time;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> M >> N;
    matrix.assign(N, std::vector<int>(M, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::cout << bfs();
    return 0;
}