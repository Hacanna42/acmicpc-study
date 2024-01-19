// 백준: 2xn 타일링 2
// https://www.acmicpc.net/problem/11727
// 2024-01-19

#include <iostream>
#include <vector>
int main() {
    int N;
    std::cin >> N;
    std::vector<long long> dp(N + 1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= N; ++i) {
        dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
    }
    std::cout << dp[N];
    return 0;
}