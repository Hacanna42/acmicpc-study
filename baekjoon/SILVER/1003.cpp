#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::vector<std::pair<int, int>> dp(41);
    dp[0] = {1, 0};
    dp[1] = {0, 1};

    for (int i = 2; i <= 40; ++i) {
        dp[i].first = dp[i - 1].first + dp[i - 2].first;
        dp[i].second = dp[i - 1].second + dp[i - 2].second;
    }

    int N;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int temp;
        std::cin >> temp;
        std::cout << dp[temp].first << " " << dp[temp].second << "\n";
    }
    return 0;
}