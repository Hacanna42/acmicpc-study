// 백준: 달팽이
// https://www.acmicpc.net/problem/1913
// 2024-02-07

#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N, target;
    cin >> N >> target;
    vector<vector<int>> matrix(N, vector<int>(N, -1));
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int counter = N * N;
    int x = 0, y = 0, dir = 0;
    int answer_x = 0, answer_y = 0;

    while (counter > 0) {
        matrix[y][x] = counter;
        if (counter == target) {
            answer_x = x + 1;
            answer_y = y + 1;
        }
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N || matrix[ny][nx] != -1) {
            dir = (dir + 1) % 4;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }
        x = nx;
        y = ny;
        --counter;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << answer_y << " " << answer_x;

    return 0;
}
