// 백준: 연결 요소의 개수
// https://www.acmicpc.net/problem/11724
// 2024-04-25

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    int N, M; // 정점 N, 간선 M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1, vector<int>());
    vector<int> visited(N + 1, false);

    for (int i = 0; i < M; ++i) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    int count = 0;

    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            ++count;
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int cur_node = q.front();
                q.pop();
                for (int next : adj[cur_node]) {
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
        }
    }

    cout << count;

    return 0;
}