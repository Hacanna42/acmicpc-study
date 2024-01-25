// 백준: 토마토 - 3D
// https://www.acmicpc.net/problem/7569
// 2024-01-25

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

std::vector<std::vector<std::vector<int> > > matrix;
int M, N, H;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dh[2] = {1, -1};

struct Node {
    int x, y, h;
    int time;
};

int bfs() {
    std::queue<Node> q;

    // 토마토 초기값을 큐에 넣기
    for (int h = 0; h < H; ++h) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (matrix[h][i][j] == 1) {
                    Node node;
                    node.h = h;
                    node.y = i;
                    node.x = j;
                    node.time = 0;
                    q.push(node);
                }
            }
        }
    }

    int answer_time = 0;
    while (!q.empty()) {
        int current_x = q.front().x;
        int current_y = q.front().y;
        int current_h = q.front().h;
        int time = q.front().time;
        q.pop();

        answer_time = time;
        // 현재 층 체크
        for (int i = 0; i < 4; ++i) {
            int next_x = current_x + dx[i];
            int next_y = current_y + dy[i];
            // valid check
            if (next_x >= 0 && next_y >= 0 && next_x < M && next_y < N) {
                if (matrix[current_h][next_y][next_x] == 0) {
                    q.push({next_x, next_y, current_h, time + 1});
                    matrix[current_h][next_y][next_x] = 1;
                }
            }
        }

        // 위 아래 층 체크
        for (int i = 0; i < 2; ++i) {
            int next_h = current_h + dh[i];
            // valid check
            if (next_h >= 0 && next_h < H) {
                if (matrix[next_h][current_y][current_x] == 0) {
                    q.push({current_x, current_y, next_h, time + 1});
                    matrix[next_h][current_y][current_x] = 1;
                }
            }
        }
    }

    // 다 익었는지 체크
    for (int h = 0; h < H; ++h) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (matrix[h][i][j] == 0) {
                    return -1;
                }
            }
        }
    }
    return answer_time;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> M >> N >> H;
    matrix.assign(H, std::vector<std::vector<int> >(N, std::vector<int>(M, 0)));
    for (int h = 0; h < H; ++h) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                std::cin >> matrix[h][i][j];
            }
        }
    }

    std::cout << bfs();
    return 0;
}