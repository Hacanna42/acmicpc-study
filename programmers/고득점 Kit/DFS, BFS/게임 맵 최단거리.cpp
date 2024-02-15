#include <queue>
#include <utility>
#include <vector>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(vector<vector<int>> &maps) {
    int N = maps.size();
    int M = maps[0].size();
    vector<vector<bool>> visited(101, vector<bool>(101));
    queue<pair<pair<int, int>, int>> q; // (X, Y), w
    q.push({{0, 0}, 1});
    visited[0][0] = true;

    while (!q.empty()) {
        int current_x = q.front().first.first;
        int current_y = q.front().first.second;
        int current_time = q.front().second;
        q.pop();

        // 도착 체크
        if (current_x == M - 1 && current_y == N - 1) {
            return current_time;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = current_x + dx[i];
            int ny = current_y + dy[i];
            // valid check
            if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
                if (!visited[ny][nx] && maps[ny][nx] != 0) {
                    q.push({{nx, ny}, current_time + 1});
                    visited[ny][nx] = true;
                }
            }
        }
    }
    return -1;
}

int solution(vector<vector<int>> maps) { return bfs(maps); }