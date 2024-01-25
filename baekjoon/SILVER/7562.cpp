// 백준: 나이트의 이동
// https://www.acmicpc.net/problem/7562
// 2024-01-25

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

int bfs(std::vector<std::vector<bool> >& board, int x, int y, int goal_x,
        int goal_y, int& l) {
    std::queue<std::pair<std::pair<int, int>, int> > q;
    q.push({{x, y}, 0});
    board[x][y] = true;

    while (!q.empty()) {
        int current_x, current_y, cnt;
        current_x = q.front().first.first;
        current_y = q.front().first.second;
        cnt = q.front().second;
        q.pop();

        // when arrive
        if (current_x == goal_x && current_y == goal_y) {
            return cnt;
        }

        for (int i = 0; i < 8; ++i) {
            int next_x = current_x + dx[i];
            int next_y = current_y + dy[i];
            // valid check
            if (next_x >= 0 && next_y >= 0 && next_x < l && next_y < l) {
                if (!board[next_x][next_y]) {
                    q.push({{next_x, next_y}, cnt + 1});
                    board[next_x][next_y] = true;
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
    int tc;
    std::cin >> tc;
    for (int i = 0; i < tc; ++i) {
        // 테스트 케이스
        int l, x, y, gt, gy;
        std::cin >> l >> x >> y >> gt >> gy;
        std::vector<std::vector<bool> > board(l, std::vector<bool>(l, false));
        std::cout << bfs(board, x, y, gt, gy, l) << "\n";
    }
    return 0;
}