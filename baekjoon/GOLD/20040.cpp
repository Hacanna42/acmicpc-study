// 사이클 게임
// https://www.acmicpc.net/problem/20040
// 2024-06-20

/*
union-find를 사용해서 두 정점이 이미 같은 집합에 속하는지 확인한다.
속한다면 사이클을 이루는 것.
*/

#include <iostream>
#include <vector>
using namespace std;

int find(int v, vector<int> &parents) {
    if (parents[v] != v)
        parents[v] = find(parents[v], parents);
    return parents[v];
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
    int n; // 점의 개수 n
    int m; // 차례의 수 m
    cin >> n >> m;
    vector<int> parents(n);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; ++i) {
        parents[i] = i;
    }

    // 게임 시작
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        if (find(u, parents) == find(v, parents)) { // 사이클
            cout << i;
            return 0; // 종료
        }
        unionSets(u, v, parents, rank);
    }
    cout << "0";
    return 0;
}