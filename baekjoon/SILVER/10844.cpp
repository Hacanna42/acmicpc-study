// 백준: 쉬운 계단 수
// https://www.acmicpc.net/problem/10844
// 2024-01-11

#include <iostream>
#include <vector>
std::vector<std::vector<long long> > memo;

long long dp(int n) {
    // Memoization initializing
    for (int i = 1; i <= 9; ++i) {
        memo[1][i]++;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= 9; ++j) {
            if (j == 0)
                memo[i][j] = memo[i - 1][1];
            else if (j == 9)
                memo[i][j] = memo[i - 1][8];
            else
                memo[i][j] =
                    (memo[i - 1][j - 1] + memo[i - 1][j + 1]) % 1000000000;
        }
    }

    long long sum = 0;
    for (int i = 0; i <= 9; ++i) {
        sum = (sum + memo[n][i]) % 1000000000;
    }
    return sum;
}

int main() {
    int N;
    std::cin >> N;
    memo.assign(N + 1, std::vector<long long>(10, 0));
    std::cout << dp(N);
    return 0;
}