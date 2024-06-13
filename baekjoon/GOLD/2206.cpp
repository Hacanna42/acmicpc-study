// 백준: 벽 부수고 이동하기
// https://www.acmicpc.net/problem/2206
// 2024-01-25

#include <iostream>
#include <queue>
#include <string>
#include <vector>

/* visited vector에 대해, 벽을 부수고 그 위치에 도달한 경우와, 벽을 부수지 않고
그 위치에 도달한 경우 두개를 나눠야 함. */

int N, M;
std::vector<std::vector<int>> matrix;
std::vector<std::vector<std::vector<bool>>> visited;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct Node {
    int x, y;
    bool item;
    int time;
};

int bfs() {
    std::queue<Node> q;
    q.push({0, 0, true, 1});
    visited[0][0][0] = true;
    // visited[0][0][1] = true;

    int answer_time = 0;

    while (!q.empty()) {
        int current_x = q.front().x;
        int current_y = q.front().y;
        bool item = q.front().item;
        int time = q.front().time;
        q.pop();

        answer_time = time;

        // 도착했는지 체크
        if (current_x == M - 1 && current_y == N - 1)
            return answer_time;

        // 가능한 4개의 경로
        for (int i = 0; i < 4; ++i) {
            int next_x = current_x + dx[i];
            int next_y = current_y + dy[i];

            // valid check
            if (next_x >= 0 && next_y >= 0 && next_x < M && next_y < N) {
                // 벽을 부수지 않을 경우 (빈 경로의 경우)
                if (matrix[next_y][next_x] == 0 && !visited[next_y][next_x][!item]) {
                    q.push({next_x, next_y, item, time + 1});
                    visited[next_y][next_x][!item] = true;
                }
                // 경로가 막혀있고, 벽을 뚫을 기회가 남아있는 경우
                else if (item && !visited[next_y][next_x][1]) {
                    q.push({next_x, next_y, false, time + 1});
                    visited[next_y][next_x][1] = true;
                }
            }
        }
    }
    return -1;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> N >> M;
    matrix.assign(N, std::vector<int>(M, 0));
    visited.assign(N, std::vector<std::vector<bool>>(M, std::vector<bool>(2, false)));

    std::cin.ignore();
    std::string line;
    for (int i = 0; i < N; ++i) {
        std::cin >> line;
        for (int j = 0; j < M; ++j) {
            matrix[i][j] = line[j] - '0';
        }
    }

    std::cout << bfs();
    return 0;
}