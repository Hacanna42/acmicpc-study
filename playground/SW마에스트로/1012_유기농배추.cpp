#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<vector<int>> map;
int M, N, K; // 가로, 세로

void dfs(int x, int y) {
    map[y][x] = 0;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
            if (map[ny][nx] == 1)
                dfs(nx, ny);
        }
    }
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        cin >> M >> N;
        map.assign(N, vector<int>(M, 0));
        cin >> K; // 배추 개수
        for (int i = 0; i < K; ++i) {
            int x, y;
            cin >> x >> y;
            map[y][x] = 1;
        }
        int counter = 0;
        // DFS 돌리고 지렁이수 계산
        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < M; ++x) {
                if (map[y][x] == 1) {
                    ++counter;
                    dfs(x, y);
                }
            }
        }

        cout << counter << "\n";
    }
    return 0;
}