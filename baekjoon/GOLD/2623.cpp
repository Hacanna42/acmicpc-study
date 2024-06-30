// 백준: 음악 프로그램
// https://www.acmicpc.net/problem/2623
// 2024-06-30

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N; // 가수의 수 N
    int M; // 보조 피디의 수 M
    cin >> N >> M;
    vector<vector<int>> adj(N + 1, vector<int>()); // 1-based index
    vector<int> in_degree(N + 1, 0);
    for (int i = 0; i < M; ++i) {
        int t;
        cin >> t;
        int prev_singer;
        cin >> prev_singer;           // 첫 가수
        for (int j = 1; j < t; ++j) { // PD의 담당 가수들
            int cur_singer;
            cin >> cur_singer;
            adj[prev_singer].push_back(cur_singer);
            ++in_degree[cur_singer]; // 진입차수 +1
            prev_singer = cur_singer;
        }
    }

    queue<int> q;
    for (int i = 1; i <= N; ++i) { // 진입 차수가 0인 노드를 모두 큐에 삽입
        if (in_degree[i] == 0)
            q.push(i);
    }

    vector<int> ans;

    while (!q.empty()) {
        int cur_node = q.front();
        q.pop();

        ans.push_back(cur_node);

        for (const auto &next : adj[cur_node]) {
            --in_degree[next];
            if (in_degree[next] == 0)
                q.push(next);
        }
    }

    // 정답 출력
    if (ans.size() < N - 1) // 순서를 정하는게 불가능
        cout << "0";
    else { // 가능
        for (const auto &next : ans) {
            cout << next << "\n";
        }
    }
    return 0;
}