// 백준: 바이러스
// https://www.acmicpc.net/problem/2606
// 2024-01-19

#include <iostream>
#include <set>
#include <vector>

std::set<int> visited;
std::vector<std::vector<int> > v;

void dfs(int node);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N, M;
    std::cin >> N >> M;
    v.resize(N);
    for (int i = 0; i < M; ++i) {
        int from, to;
        std::cin >> from >> to;
        --from;
        --to;
        v[from].push_back(to);
        v[to].push_back(from);
    }

    dfs(0);
    std::cout << visited.size() - 1;
    return 0;
}

void dfs(int node) {
    visited.insert(node);
    for (int i = 0; i < v[node].size(); ++i) {
        int next = v[node][i];
        if (visited.find(next) == visited.end()) {
            dfs(next);
        }
    }
}