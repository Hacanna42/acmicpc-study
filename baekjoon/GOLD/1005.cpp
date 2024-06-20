// 백준: ACM Craft
// https://www.acmicpc.net/problem/1005
// 2024-06-20

/*
위상 정렬을 이용해야 한다. 위상 정렬은 사이클이 없는 방향그래프에서만 사용할 수 있고.
순서가 정해져있는 일련의 작업을 수행해야 할 때 사용할 수 있다.

* 진입 차수와 진출 차수
: 진입 차수는 특정한 노드로 들어오는 간선의 수, 진출 차수는 특정한 노드에서 나가는 간선의 수.
진입 차수가 0인 노드를 큐에 넣는다 (현재 노드를 실행하기 위해 선행해야 할 노드가 없다 (즉, 부모))
큐가 빌떄까지 다음을 반복한다:
1. 큐에서 원소를 꺼내서, 해당 노드에서 나가는 간선을 그래프에서 제거한다.
2. 새롭게 진입 차수가 0이 된 노드를 큐에 삽입한다.
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int TC;
    cin >> TC;
    while (TC--) {
        int N; // 건물의 개수 N
        int K; // 건물간의 건설순서 규칙 개수 K
        cin >> N >> K;
        vector<int> build_time(N + 1, 0);
        for (int i = 1; i <= N; ++i) {
            cin >> build_time[i];
        }

        vector<int> in_degree(N + 1, 0);
        vector<vector<int>> adj(N + 1, vector<int>());
        for (int i = 0; i < K; ++i) {
            int X, Y; //  건설 순서 X -> Y
            cin >> X >> Y;
            adj[X].push_back(Y);
            ++in_degree[Y]; // Y의 진입 차수 증가
        }

        int W;
        cin >> W; // W 입력

        queue<int> q;
        vector<int> dist(N + 1, 0);
        // 진입 차수가 0인 노드를 큐에 삽입
        for (int i = 1; i <= N; ++i) {
            if (in_degree[i] == 0) {
                q.push(i);
                dist[i] = build_time[i];
            }
        }

        while (!q.empty()) { // 큐가 빌때까지 반복
            int cur_node = q.front();
            q.pop();

            for (const int &next : adj[cur_node]) {
                dist[next] = max(dist[next], dist[cur_node] + build_time[next]);
                if (--in_degree[next] == 0) {
                    q.push(next);
                }
            }
        }

        cout << dist[W] << "\n";
    }
    return 0;
}