// 백준: 점프
// 2024-02-04
// https://www.acmicpc.net/problem/1890

#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin >> N;
    std::vector<std::vector<int>> matrix(N, std::vector<int>(N));
    std::vector<std::vector<long long>> dp(N, std::vector<long long>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int temp;
            std::cin >> temp;
            matrix[i][j] = temp;
        }
    }

    dp[0][0] = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (dp[i][j] == 0 || (i == N - 1 && j == N - 1))
                continue;
            int distance = matrix[i][j];
            int down = i + distance;
            int right = j + distance;

            if (down < N)
                dp[down][j] += dp[i][j];
            if (right < N)
                dp[i][right] += dp[i][j];
        }
    }

    std::cout << dp[N - 1][N - 1];
    return 0;
}