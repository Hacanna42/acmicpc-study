// 백준: 동전 1
// https://www.acmicpc.net/problem/2293
// 2024-01-20

#include <iostream>
#include <vector>

std::vector<int> coins;
std::vector<int> dp(10001, 0);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int coin;
        std::cin >> coin;
        coins.push_back(coin);
    }

    dp[0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = coins[i]; j <= k; ++j) {
            dp[j] += dp[j - coins[i]];
        }
    }

    std::cout << dp[k];
    return 0;
}