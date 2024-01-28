// 백준: 운동
// https://www.acmicpc.net/problem/1956
// 2024-01-28

#include <limits.h>

#include <iostream>
#include <vector>

std::vector<std::vector<long long> > dist;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int V, E;
    std::cin >> V >> E;
    dist.resize(V + 1, std::vector<long long>(V + 1, LLONG_MAX));

    // // 자기자신 0으로 초기화
    // for (int i = 1; i <= V; ++i) {
    //     dist[i][i] = 0;
    // }

    for (int i = 0; i < E; ++i) {
        int a, b, c;  // a -> b | c
        std::cin >> a >> b >> c;
        if (dist[a][b] > c) dist[a][b] = c;
    }

    for (int k = 1; k <= V; ++k) {
        for (int i = 1; i <= V; ++i) {
            for (int j = 1; j <= V; ++j) {
                if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX) {
                    if (dist[i][j] > dist[i][k] + dist[k][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    long long mincycle = LLONG_MAX;
    for (int i = 1; i <= V; ++i) {
        if (dist[i][i] < mincycle) {
            mincycle = dist[i][i];
        }
    }

    // 사이클 없음
    if (mincycle == 0 || mincycle == LLONG_MAX) {
        std::cout << "-1";
    } else {
        std::cout << mincycle;
    }
    return 0;
}