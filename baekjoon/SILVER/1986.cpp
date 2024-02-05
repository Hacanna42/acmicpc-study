// 백준: 체스
// https://www.acmicpc.net/problem/1986
// 2024-02-05

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

std::vector<std::vector<int>> board_info;
std::vector<std::pair<int, int>> queens; // X, Y
std::vector<std::pair<int, int>> knights;

int k_dx[] = {1, -1, 1, -1, 2, -2, 2, -2};
int k_dy[] = {2, 2, -2, -2, 1, -1, -1, 1};

int q_dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int q_dy[] = {1, -1, 0, 0, -1, 1, -1, 1};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int height, width;
    std::cin >> height >> width;
    board_info.assign(height + 1, std::vector<int>(width + 1, 0)); // 0 안전 1 위험 2 퀸 3 나이트 4 폰
    // 퀸 입력
    int queen_num, knight_num, pawn_num;
    std::cin >> queen_num;
    for (int i = 1; i <= queen_num; ++i) {
        int x, y;
        std::cin >> y >> x;
        queens.push_back({x, y});
        board_info[y][x] = 2;
    }
    std::cin >> knight_num;
    for (int i = 1; i <= knight_num; ++i) {
        int x, y;
        std::cin >> y >> x;
        knights.push_back({x, y});
        board_info[y][x] = 3;
    }
    std::cin >> pawn_num;
    for (int i = 1; i <= pawn_num; ++i) {
        int x, y;
        std::cin >> y >> x;
        board_info[y][x] = 4;
    }

    // 퀸 경로 계산
    for (const auto q : queens) {
        for (int i = 0; i < 8; ++i) {
            int nx = q.first + q_dx[i];
            int ny = q.second + q_dy[i];
            while (1) {
                if (!(nx > 0 && ny > 0 && nx <= width && ny <= height))
                    break; // 맵 밖 종료
                if (board_info[ny][nx] == 4 || board_info[ny][nx] == 3)
                    break; // 장애물 종료
                board_info[ny][nx] = 1;
                nx += q_dx[i];
                ny += q_dy[i];
            }
        }
    }

    // 나이트 경로 계산
    for (const auto k : knights) {
        for (int i = 0; i < 8; ++i) {
            int nx = k.first + k_dx[i];
            int ny = k.second + k_dy[i];
            if (!(nx > 0 && ny > 0 && nx <= width && ny <= height))
                continue; // 맵 밖 스킵
            board_info[ny][nx] = 1;
        }
    }
    int count = 0;
    for (int i = 1; i <= height; ++i) {
        for (int j = 1; j <= width; ++j) {
            if (board_info[i][j] == 0)
                count++;
        }
    }

    std::cout << count;

    return 0;
}
