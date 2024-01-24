// 백준: 미로 탐색
// https://www.acmicpc.net/problem/2178
// 2024-01-24

#include <iostream>
#include <queue>
#include <string>
#include <vector>

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(std::vector<std::vector<int> >& maze, int N, int M) {
    std::queue<std::pair<int, int> > q;
    q.push({0, 0});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (maze[nx][ny] == 1) {
                    q.push({nx, ny});
                    maze[nx][ny] = maze[x][y] + 1;
                }
            }
        }
    }

    return maze[N - 1][M - 1];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int> > maze(N, std::vector<int>(M));

    std::string line;
    for (int y = 0; y < N; ++y) {
        std::cin >> line;
        for (int x = 0; x < M; ++x) {
            maze[y][x] = line[x] - '0';
        }
    }

    std::cout << bfs(maze, N, M);
    return 0;
}