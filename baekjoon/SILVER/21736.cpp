// 백준: 헌내기는 친구가 필요해
// https://www.acmicpc.net/problem/21736
// 2024-04-29

/*
큐에서 뺄 때 방문 체크 하는 것은 중복 방문이 일어날 수 있다.
큐에 넣을때 방문 체크 하는 것이 더 효율적이다.
*/

#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M;
    cin >> N >> M;
    pair<int, int> startPos;
    vector<vector<char>> map(N + 1, vector<char>(M + 1)); // 방문 표시 겸용
    for (int r = 1; r <= N; ++r) {
        for (int c = 1; c <= M; ++c) {
            char next;
            cin >> next;
            map[r][c] = next;
            if (next == 'I')
                startPos = {r, c};
        }
    }
    int count = 0;
    queue<pair<int, int>> q;
    q.push({startPos.first, startPos.second});

    while (!q.empty()) {
        int cur_r = q.front().first;
        int cur_c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int next_r = cur_r + dr[i];
            int next_c = cur_c + dc[i];
            if (next_r > 0 && next_c > 0 && next_r <= N && next_c <= M && map[next_r][next_c] != 'X') { // VALID CHECK
                if (map[next_r][next_c] == 'P')
                    count++;
                map[next_r][next_c] = 'X'; // 큐에 넣을 때 방문 표시
                q.push({next_r, next_c});
            }
        }
    }

    cout << (count != 0 ? to_string(count) : "TT");
    return 0;
}