// 백준: 줄 세우기
// https://www.acmicpc.net/problem/2252
// 2024-06-28

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    /*
    비교 정보가 A B로 주어지는데, A가 B의 앞에 서야한다는 정보이다.
    이를 그래프 상에서 A -> B로 표현하자. 그러면 진입차수가 0개인 노드가 제일 키가 크다고 할 수 있다.

    위상 정렬을 이용해서 풀어야 한다.
    진입차수와 진출차수. 진입차수가 0인 노드를 큐에 넣고 다음을 반복한다
    1. 큐에서 원소를 꺼내서, 해당 노드가 나가는 간선을 제거한다(진입차수를 -1한다).
    2. 새롭게 진입차수가 0이 된 노드를 큐에 넣는다.
    */

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; // 학생 수 N (1번부터 N번까지)
    int M; // 비교 회수 M
    cin >> N >> M;
    vector<vector<int>> adj(N + 1, vector<int>());
    vector<int> in_degree(N+1, 0);
    for (int i=0;i<M;++i) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        ++in_degree[B];
    }

    queue<int> q;
    for (int i=1;i<=N;++i) {
        // 진입차수가 0인 노드를 큐에 삽입
        if (in_degree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int cur_i = q.front();
        q.pop();
        cout << cur_i << " ";
        for (const auto& next : adj[cur_i]) {
            if (--in_degree[next] == 0) { // 해당 노드가 나가는 간선 제거
                q.push(next); // 새롭게 진입차수가 0이 된 노드 큐에 삽입
            }
        }
    }


    return 0;
} 