// 백준: 타임머신
// https://www.acmicpc.net/problem/11657
// 2024-01-27
// 벨만-포드 알고리즘 입문 문제

#include <limits.h>

#include <iostream>
#include <vector>

std::vector<std::vector<std::pair<int, int> > > adj;
std::vector<long long> dist;

int N, M;

int bellman_ford() {
    dist[1] = 0;
    for (int i = 1; i <= N - 1; ++i) {
        for (int j = 1; j <= N; ++j) {
            for (auto& p : adj[j]) {
                int next = p.second;
                long long weight = p.first;

                if (dist[j] != LLONG_MAX && dist[next] > dist[j] + weight) {
                    dist[next] = dist[j] + weight;
                }
            }
        }
    }

    // 음의 사이클 검사
    for (int j = 1; j <= N; ++j) {
        for (auto& p : adj[j]) {
            int next = p.second;
            long long weight = p.first;
            if (dist[j] != LLONG_MAX && dist[next] > dist[j] + weight) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> N >> M;
    adj.resize(N + 1);
    dist.resize(N + 1, LLONG_MAX);
    for (int i = 0; i < M; ++i) {
        int A, B, C;
        std::cin >> A >> B >> C;
        adj[A].push_back({C, B});
    }

    if (bellman_ford()) {
        for (int i = 2; i <= N; ++i) {
            if (dist[i] != LLONG_MAX)
                std::cout << dist[i] << "\n";
            else
                std::cout << "-1"
                          << "\n";
        }
    } else
        std::cout << "-1";

    return 0;
}