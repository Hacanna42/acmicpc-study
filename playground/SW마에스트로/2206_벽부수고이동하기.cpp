#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

struct Node {
    int r;
    int c;
    bool itemUsed;
    int time;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    cin.ignore();
    vector<vector<int>> map(N + 1, vector<int>(M + 1));
    for (int r = 1; r <= N; ++r) {
        string s;
        cin >> s;
        for (int c = 1; c <= M; ++c) {
            map[r][c] = s[c - 1] - '0';
        }
    }

    vector<vector<bool>> visited(N + 1, vector<bool>(M + 1, false));
    vector<vector<bool>> visited_with_item(N + 1, vector<bool>(M + 1, false));
    queue<Node> q;
    q.push({1, 1, false, 1});
    visited[1][1] = true;

    while (!q.empty()) {
        Node current = q.front();
        q.pop();
        int cur_r = current.r;
        int cur_c = current.c;
        int cur_time = current.time;
        bool cur_itemUsed = current.itemUsed;
        if (cur_r == N && cur_c == M) {
            cout << cur_time;
            return 0;
        }

        for (int i = 0; i < 4; ++i) {
            int next_r = cur_r + dr[i];
            int next_c = cur_c + dc[i];
            // VALID CHECK
            if (next_r > 0 && next_c > 0 && next_r <= N && next_c <= M) {
                // 아이템을 사용한 전과가 있을 때
                if (cur_itemUsed) {
                    if (map[next_r][next_c] == 0 && !visited_with_item[next_r][next_c]) { // 비어있으면
                        visited_with_item[next_r][next_c] = true;
                        q.push({next_r, next_c, cur_itemUsed, cur_time + 1});
                    }
                }
                // 없을 때
                else if (!cur_itemUsed) {
                    if (map[next_r][next_c] == 0 && !visited[next_r][next_c]) { // 비어있으면
                        visited[next_r][next_c] = true;
                        q.push({next_r, next_c, cur_itemUsed, cur_time + 1});
                    } else if (map[next_r][next_c] == 1 && !visited[next_r][next_c]) { // 막혀있고, 아이템을 쓰기로 결정
                        visited[next_r][next_c] = true;
                        q.push({next_r, next_c, true, cur_time + 1});
                    }
                }
            }
        }
    }

    // 탐색 실패
    cout << "-1";
    return 0;
}