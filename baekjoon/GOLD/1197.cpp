// 백준: 최소 스패닝 트리
// https://www.acmicpc.net/problem/1197
// 2024-06-13

/* Spanning Tree (신장 트리) 란?
모든 정점이 연결되어 있고, 사이클이 없는 그래프 (통신 네트워크 구축에 주로 쓰임)
Minimum Spanning Tree (최소 신장 트리) 는 그 중에서도 최소 가중치를 가지는 신장 트리

Spanning Tree 구하는 법: 단순히 탐색 도중에 사용된 간선을 모아서 만들 수 있음
MST 구하는 법: 탐욕적(Greedy method)으로 구함. 가중치 간선을 오름차순 정렬하고 이음. union-find로 루트 체크하고 사이클이 생기면 건너 뜀.
*/

// 의아한 사항: 신장 트리가 성립하려면 간선이 최소 V-1개어야 하지 않나? 본 문제에 이러한 조건은 명시되어 있지 않다.

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// union-find 먼저 구현
int find(int node, vector<int> &parents) {
    if (parents[node] != node)
        parents[node] = find(parents[node], parents);
    return parents[node];
}

void unionSets(int u, int v, vector<int> &parents, vector<int> &rank) {
    int rootU = find(u, parents);
    int rootV = find(v, parents);

    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parents[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parents[rootU] = rootV;
        } else {
            parents[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int V, E; // 정점의 개수 V, 간선의 개수 E
    cin >> V >> E;
    vector<pair<int, pair<int, int>>> edges; // 간선 리스트
    vector<int> parents(V + 1, 0);
    vector<int> rank(V + 1, 0);
    for (int i = 1; i <= V; ++i) {
        parents[i] = i; // 부모 초기화
    }

    for (int i = 0; i < E; ++i) {
        int A, B, W;
        cin >> A >> B >> W;
        edges.push_back({W, {A, B}}); // A-B, W
    }

    sort(edges.begin(), edges.end());

    // 그리디하게 제일 가중치가 적은 간선부터 선택
    int weight_sum = 0;
    for (const auto &edge : edges) {
        int A = edge.second.first;
        int B = edge.second.second;
        if (find(A, parents) != find(B, parents)) { // 각 정점의 루트가 같으면 안됨
            weight_sum += edge.first;               // 가중치 합산
            unionSets(A, B, parents, rank);
        }
    }

    cout << weight_sum;

    return 0;
}