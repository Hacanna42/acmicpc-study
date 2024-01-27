// 백준: 플로이드
// https://www.acmicpc.net/problem/11404
// 2024-01-27

#include <limits.h>

#include <iostream>
#include <utility>
#include <vector>

std::vector<std::vector<long long> > dist;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    dist.resize(n + 1, std::vector<long long>(n + 1, LLONG_MAX));

    // 자기 자신과의 거리를 0으로 초기화
    for (int i = 1; i <= n; ++i) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        std::cin >> a >> b >> c;
        if (dist[a][b] > c) dist[a][b] = c;
    }

    // 플로이드 워셜
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX &&
                    dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // 결과 출력
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dist[i][j] == LLONG_MAX)
                std::cout << "0";
            else
                std::cout << dist[i][j];
            std::cout << " ";
        }
        std::cout << "\n";
    }

    return 0;
}