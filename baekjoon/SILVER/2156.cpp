// 백준: 포도주 시식
// https://www.acmicpc.net/problem/2156
// 2024-01-11

#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> amount_of_wines(10002, 0);
std::vector<int> memo(10002, 0);
int dp(int n) {
    // Memoization initialize
    memo[1] = amount_of_wines[1];
    memo[2] = amount_of_wines[1] + amount_of_wines[2];
    memo[3] = std::max({amount_of_wines[1] + amount_of_wines[3],
                        amount_of_wines[2] + amount_of_wines[3],
                        amount_of_wines[1] + amount_of_wines[2]});

    for (int i = 4; i <= n; ++i) {
        memo[i] =
            std::max({memo[i - 3] + amount_of_wines[i - 1] + amount_of_wines[i],
                      memo[i - 2] + amount_of_wines[i], memo[i - 1]});
    }

    return std::max(memo[n], memo[n - 1]);
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N;
    std::cin >> N;
    for (int i = 1; i <= N; ++i) {
        std::cin >> amount_of_wines[i];
    }
    std::cout << dp(N);
    return 0;
}