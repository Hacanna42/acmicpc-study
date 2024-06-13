// 백준: 도시 분할 계획
// https://www.acmicpc.net/problem/1647
// 2024-06-13

/*
딱 봐도, 최소 스패닝 트리(MST)의 응용 문제이다.
MST를 구하고 최대 간선 하나를 지우면 되는 문제.
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// union-find 구현
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
    int N, M; // 집의 개수 N, 길의 개수 M
    cin >> N >> M;
    vector<pair<int, pair<int, int>>> edges;
    vector<int> parents(N + 1, 0);
    vector<int> rank(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        parents[i] = i;
    }
    for (int i = 0; i < M; ++i) {
        int A, B, W;
        cin >> A >> B >> W;
        edges.push_back({W, {A, B}}); // 간선 정보 추가
    }

    sort(edges.begin(), edges.end()); // 오름차순으로 정렬 (그리디)

    int weight_sum = 0;
    int max_edge = 0;
    for (const auto &edge : edges) {
        int A = edge.second.first;
        int B = edge.second.second;
        if (find(A, parents) != find(B, parents)) { // 사이클이 아닐 경우만
            unionSets(A, B, parents, rank);
            weight_sum += edge.first; // 가중치 합산
            max_edge = max(max_edge, edge.first);
        }
    }

    cout << weight_sum - max_edge;
    return 0;
}