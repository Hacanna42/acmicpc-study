// 백준: 1로 만들기
// https://www.acmicpc.net/problem/1463
// 2024-01-11

/* 점화식
dp[i] 를 i의 최선의 연산 수라고 가정하면
dp[i] = min(dp[i/3], dp[i/2], dp[i-1]) + 1;
*/
#include <algorithm>
#include <iostream>
int *memo;
int dp(int n) {
    memo[1] = 0;
    memo[2] = 1;
    memo[3] = 1;
    for (int i = 4; i < n; ++i) {
        if (i % 3 == 0 && i % 2 == 0)
            memo[i] = std::min({memo[i / 3], memo[i / 2], memo[i - 1]}) + 1;
        else if (i % 3 == 0)
            memo[i] = std::min(memo[i / 3], memo[i - 1]) + 1;
        else if (i % 2 == 0)
            memo[i] = std::min(memo[i / 2], memo[i - 1]) + 1;
        else
            memo[i] = memo[i - 1] + 1;
    }

    return memo[n - 1];
}
int main() {
    int N;
    std::cin >> N;
    memo = new int[N + 1];
    std::cout << dp(N + 1);
    delete[] memo;
    return 0;
}