// 백준: 1로 만들기
// https://www.acmicpc.net/problem/12852
// 2024-01-30

#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> dp;

void calculate_dp(int N) {
    for (int i = 2; i <= N; ++i) {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0) dp[i] = std::min(dp[i], dp[i / 2] + 1);
        if (i % 3 == 0) dp[i] = std::min(dp[i], dp[i / 3] + 1);
    }
}

void print_path(int N) {
    while (N != 1) {
        std::cout << N << " ";
        if (N % 2 == 0 && dp[N] == dp[N / 2] + 1)
            N /= 2;
        else if (N % 3 == 0 && dp[N] == dp[N / 3] + 1)
            N /= 3;
        else
            N--;
    }
    std::cout << "1";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    dp.assign(N + 1, 0);
    calculate_dp(N);
    std::cout << dp[N] << "\n";
    print_path(N);

    return 0;
}