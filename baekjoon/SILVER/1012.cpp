// 백준: 유기농 배추
// https://www.acmicpc.net/problem/1012
// 2024-01-24

#include <iostream>
#include <vector>

int to_x[4] = {1, -1, 0, 0};
int to_y[4] = {0, 0, 1, -1};

int dfs(int y, int x, int width, int height,
        std::vector<std::vector<int> >& matrix,
        std::vector<std::vector<bool> >& visited) {
    visited[y][x] = true;
    for (int i = 0; i < 4; ++i) {
        int new_x = x + to_x[i];
        int new_y = y + to_y[i];
        if (new_x >= 0 && new_y >= 0 && new_x < width && new_y < height) {
            if (matrix[new_y][new_x] == 1 && !visited[new_y][new_x]) {
                visited[new_y][new_x] = true;
                dfs(new_y, new_x, width, height, matrix, visited);
            }
        }
    }
    return 1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int tc;
    std::cin >> tc;
    for (int i = 0; i < tc; ++i) {
        int width, height, K;
        std::cin >> width >> height >> K;
        std::vector<std::vector<int> > matrix(height,
                                              std::vector<int>(width, 0));
        // 좌표 입력받기
        for (int j = 0; j < K; ++j) {
            int x, y;
            std::cin >> x >> y;
            matrix[y][x] = 1;
        }

        // DFS
        std::vector<std::vector<bool> > visited(
            height, std::vector<bool>(width, false));

        int cnt = 0;
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                if (matrix[y][x] == 1 && !visited[y][x])
                    cnt += dfs(y, x, width, height, matrix, visited);
            }
        }
        std::cout << cnt << "\n";
    }
    return 0;
}