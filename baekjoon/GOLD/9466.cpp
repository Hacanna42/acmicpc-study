// 백준: 텀 프로젝트
// https://www.acmicpc.net/problem/9466
// 2024-06-30

/*
조금만 생각해보면 규칙성을 찾을 수 있다. 학생들간에 팀을 이룬다는 것은 그래프상에서 사이클을 이룬다는 것이다.
위상 정렬에서 진입차수가 끝까지 0이 되지 않는 노드들을 의미한다.
즉 위상 정렬의 큐에 삽입되는 노드는 (진입 차수가 0인 노드) 팀을 이루지 않는다.
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int TC;
    cin >> TC;
    while (TC--) {
        int n; // 학생 수 n
        cin >> n;
        vector<vector<int>> adj(n + 1, vector<int>());
        vector<int> in_degree(n + 1, 0); // 진입차수
        for (int i = 1; i <= n; ++i) {
            int to;
            cin >> to;            // 각 학생들이 가리킨 학생 번호
            adj[i].push_back(to); // A -> B;
            ++in_degree[to];
        }

        // 위상 정렬
        queue<int> q;
        for (int i = 1; i <= n; ++i) { // 진입 차수가 0인 노드를 큐에 모두 삽입
            if (in_degree[i] == 0)
                q.push(i);
        }

        int process_count = 0; // 진입 차수가 0이 되어서 큐에 들어간 노드는 모두 팀을 이루지 못한 학생이다.
        while (!q.empty()) {
            int cur_node = q.front();
            q.pop();

            process_count++; // 팀을 이루지 못한 학생 수 +1

            for (const auto &next : adj[cur_node]) {
                --in_degree[next]; // 간선 제거
                if (in_degree[next] == 0)
                    q.push(next); // 새롭게 진입 차수가 0이 된 노드를 큐에 삽입
            }
        }

        cout << process_count << "\n";
    }
    return 0;
}