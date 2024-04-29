// 백준: 쉬운 최단거리
// https://www.acmicpc.net/problem/14940
// 2024-04-27

/*
주어진 모든 위치에 대해서 목표 지점까지의 거리를 BFS 브루트포스로 구하는 것은 너무 비효율적이다.
역으로 목표지점에서부터 가능한 모든 루트로 BFS를 통해 가면서 거리를 기록하면 되지 않을까?
*/

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

vector<vector<int>> map;
vector<vector<int>> distances;
int n, m;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    map.assign(n, vector<int>(m));
    distances.assign(n, vector<int>(m, -1));
    pair<int, int> targetPos;

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            cin >> map[r][c];
            if (map[r][c] == 0)
                distances[r][c] = 0;
            else if (map[r][c] == 2)
                targetPos = {r, c};
        }
    }

    queue<pair<int, int>> q;
    q.push(targetPos);
    distances[targetPos.first][targetPos.second] = 0;

    while (!q.empty()) {
        int cur_r = q.front().first;
        int cur_c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int next_r = cur_r + dr[i];
            int next_c = cur_c + dc[i];
            if (next_r >= 0 && next_c >= 0 && next_r < n && next_c < m && map[next_r][next_c] == 1 && distances[next_r][next_c] == -1) {
                distances[next_r][next_c] = distances[cur_r][cur_c] + 1;
                q.push({next_r, next_c});
            }
        }
    }

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            cout << distances[r][c] << " ";
        }
        cout << "\n";
    }

    return 0;
}