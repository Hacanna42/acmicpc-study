// 백준: 트리의 지름
// https://www.acmicpc.net/problem/1967
// 2024-05-17

/*
무조건 잎새 노드 <-> 잎새 노드(자식이 없는 노드) 만 최댓값이 될 수 있다.
각 잎새 노드에서부터 가능한 끝 지점까지 DFS 탐색하고, 백트래킹으로 모든 경우의 수에 대해 max_score을 업데이트 한다.

PS. 트리는 사이클이 없는 연결 그래프이므로, 두 노드 사이의 경로는 유일하다.
따라서, 임의의 노드에서 가장 먼 노드를 찾으면, 이 노드는 지름을 구성하는 끝 점중 하나가 된다.
즉, 임의의 노드에서 가장 먼 노드를 찾고. 그 노드에서 가장 먼 노드까지의 거리가 지름의 길이가 된다.
*/

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
vector<vector<pair<int, int>>> adj;
int max_score = 0;

void dfs(int current_node, int length, vector<bool> &visited) {
    // current_node가 잎새 노드인지 확인하거나..

    for (const auto &next : adj[current_node]) {
        if (!visited[next.first]) { // 아직 방문하지 않았다면
            visited[next.first] = true;
            dfs(next.first, length + next.second, visited);
            visited[next.first] = false; // 백트래킹
        }
    }

    // 끝에서 업데이트 (여기에 도달하는 경우는 마지막 노드밖에 없다)
    max_score = max(max_score, length);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<bool> check_leaf_nodes(n + 1, true);
    adj.assign(n + 1, vector<pair<int, int>>()); // 인접 노드, 가중치
    for (int i = 1; i < n; ++i) {
        int parent_node, children_node, v;
        cin >> parent_node >> children_node >> v;
        adj[parent_node].push_back({children_node, v});
        adj[children_node].push_back({parent_node, v});
        check_leaf_nodes[parent_node] = false; // 잎새 노드가 아니라고 체크
    }

    vector<int> leaf_nodes;
    for (int i = 1; i < n + 1; ++i) {
        if (check_leaf_nodes[i])
            leaf_nodes.push_back(i);
    }
    int SIZE = leaf_nodes.size();
    for (int i = 0; i < SIZE; ++i) {
        // 모든 잎새 노드에서부터 시작해서. 끝에 도달할 때 현재까지의 점수를 기록하고 백트래킹
        vector<bool> visited(n + 1, false);
        visited[leaf_nodes[i]] = true; // 시작 지점 방문 체크
        dfs(leaf_nodes[i], 0, visited);
    }

    cout << max_score;

    return 0;
};