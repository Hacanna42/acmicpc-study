// 백준: 내리막 길
// https://www.acmicpc.net/problem/1520
// 2024-01-18

#include <iostream>
#include <vector>
using namespace std;
int M, N;
vector<vector<int> > DP;
vector<vector<int> > map;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int dfs(int X, int Y);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> M >> N;
    map.assign(M, vector<int>(N));
    DP.assign(M, vector<int>(N, -1));
    for (int y = 0; y < M; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> map[y][x];
        }
    }

    cout << dfs(0, 0);

    return 0;
}

int dfs(int Y, int X) {
    // 도착하면 1 반환
    if (Y == M - 1 && X == N - 1) return 1;
    // 저장된 경로가 존재하면 대체
    if (DP[Y][X] != -1) return DP[Y][X];

    // 체크인
    DP[Y][X] = 0;

    // 가능한 4개의 경로 모두 탐색
    for (int i = 0; i < 4; ++i) {
        int nx = X + dx[i];
        int ny = Y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
            if (map[ny][nx] < map[Y][X]) {
                DP[Y][X] += dfs(ny, nx);
            }
        }
    }
    return DP[Y][X];
}