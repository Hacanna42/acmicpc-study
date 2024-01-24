// 백준: 단지번호붙이기
// https://www.acmicpc.net/problem/2667
// 2024-01-24

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
std::vector<std::vector<int> > matrix;
std::vector<std::vector<bool> > visited;
std::vector<int> count;

int N;
int tx[4] = {1, -1, 0, 0};
int ty[4] = {0, 0, 1, -1};

int dfs(int x, int y) {
    visited[x][y] = true;
    int cnt = 1;
    for (int i = 0; i < 4; ++i) {
        int to_x = x + tx[i];
        int to_y = y + ty[i];
        // valid check
        if (to_x >= 0 && to_x < N && to_y >= 0 && to_y < N) {
            if (matrix[to_x][to_y] == 1 && !visited[to_x][to_y]) {
                cnt += dfs(to_x, to_y);
            }
        }
    }
    return cnt;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> N;
    matrix.assign(N, std::vector<int>(N, 0));
    visited.assign(N, std::vector<bool>(N, false));
    std::string line;
    for (int y = 0; y < N; ++y) {
        std::cin >> line;
        for (int x = 0; x < N; ++x) {
            matrix[x][y] = line[x] - '0';
        }
    }
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            if (matrix[x][y] == 1 && !visited[x][y]) {
                // 집이 있으면
                count.push_back(dfs(x, y));
            }
        }
    }

    std::sort(count.begin(), count.end());

    std::cout << count.size() << "\n";
    for (int c : count) {
        std::cout << c << "\n";
    }
    return 0;
}