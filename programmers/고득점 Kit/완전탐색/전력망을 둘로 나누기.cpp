#include <algorithm>
#include <cmath>
#include <limits.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;

vector<vector<pair<int, bool>>> adj;

int check(int node, vector<bool> &visited) {
    visited[node] = true;
    int count = 1;
    for (const auto &[edge, pos] : adj[node]) {
        if (!visited[edge] && pos) {
            count += check(edge, visited);
        }
    }
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INT_MAX;
    adj.assign(n + 1, vector<pair<int, bool>>());
    for (int i = 0; i < n - 1; ++i) {
        int a = wires[i][0];
        int b = wires[i][1];
        adj[a].push_back({b, true});
        adj[b].push_back({a, true});
    }

    for (int i = 0; i < adj.size(); ++i) {
        for (int j = 0; j < adj[i].size(); ++j) {
            // cur: 현재 가리키는 정점
            // i: 나 자신
            int cur = adj[i][j].first;

            // 전선 연결 끊기
            for (auto &wire : adj[cur]) {
                if (wire.first == i) {
                    wire.second = false;
                    break;
                }
            }

            for (auto &wire : adj[i]) {
                if (wire.first == cur) {
                    wire.second = false;
                    break;
                }
            }

            // 체크
            vector<bool> visited(n + 1, false);
            int groupSize = check(cur, visited);
            answer = min(answer, abs(n - 2 * groupSize));

            // 돌려놓기
            // 전선 연결 끊기
            for (auto &wire : adj[cur]) {
                if (wire.first == i) {
                    wire.second = true;
                    break;
                }
            }

            for (auto &wire : adj[i]) {
                if (wire.first == cur) {
                    wire.second = true;
                    break;
                }
            }
        }
    }
    return answer;
}