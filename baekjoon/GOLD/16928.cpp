// 백준: 뱀과 사다리 게임
// https://www.acmicpc.net/problem/16928
// 2024-01-25

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

std::vector<bool> board(101, false);
std::vector<int> ladder_info(101, -1);  // 인덱스 위치 -> 값 위치
std::vector<int> snake_info(101, -1);

int ladder_num, snake_num;

int bfs() {
    // 1번째 칸 시작, 100번째 칸 도착
    // 가능한 이동 경우의 수는 1~6
    std::queue<std::pair<int, int> > q;
    q.push({1, 0});
    board[0] = true;  // 쓰지 않는 칸 비활성화
    board[1] = true;

    int answer_time = 0;
    while (!q.empty()) {
        int current_pos = q.front().first;
        int current_time = q.front().second;
        q.pop();
        answer_time = current_time;

        if (current_pos == 100) break;

        for (int i = 1; i <= 6; ++i) {
            // 가능한 경로 1~6에 대하여
            int next_pos = current_pos + i;
            if (next_pos <= 100 && !board[next_pos]) {
                // 밟은 곳에 사다리나 뱀이 있는지 check
                if (ladder_info[next_pos] != -1) {
                    // 사다리가 있다면
                    q.push({ladder_info[next_pos], current_time + 1});
                    board[ladder_info[next_pos]] = true;
                } else if (snake_info[next_pos] != -1) {
                    // 뱀이 있다면
                    q.push({snake_info[next_pos], current_time + 1});
                    board[snake_info[next_pos]] = true;
                } else {
                    // 안전하게 밟았다면
                    q.push({next_pos, current_time + 1});
                    board[next_pos] = true;
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
    std::cin >> ladder_num >> snake_num;
    for (int i = 0; i < ladder_num; ++i) {
        int from, to;
        std::cin >> from >> to;
        ladder_info[from] = to;
    }
    for (int i = 0; i < snake_num; ++i) {
        int from, to;
        std::cin >> from >> to;
        snake_info[from] = to;
    }

    std::cout << bfs();
    return 0;
}