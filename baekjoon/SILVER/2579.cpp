// 백준: 계단 오르기
// https://www.acmicpc.net/problem/2579
// 2024-01-10

#include <algorithm>
#include <iostream>
#include <vector>

int v[301];
int memo[301];

int dp(int n) {
    memo[0] = v[0];
    memo[1] = v[0] + v[1];
    memo[2] = std::max(v[0] + v[2], v[1] + v[2]);

    for (int i = 3; i < n; ++i) {
        memo[i] = std::max(memo[i - 3] + v[i - 1] + v[i], memo[i - 2] + v[i]);
    }

    return memo[n - 1];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        std::cin >> v[i];
    }
    std::cout << dp(N);
    return 0;
}