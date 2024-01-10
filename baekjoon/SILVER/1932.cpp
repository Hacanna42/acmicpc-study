// 백준: 정수 삼각형
// https://www.acmicpc.net/problem/1932
// 2024-01-10

/*
삼각형 구조에서, 자기자신 혹은 자기자신+1만을 고를 수 있다.
dp[i][j] 를 층 i와 위치 j의 최대 합이라고 하면
dp[i][j] = max(dp[i-1][j-1] + dp[i-1][j]);
*/

#include <iostream>
#include <vector>

std::vector<std::vector<int> > v(500, std::vector<int>(500));
std::vector<std::vector<int> > memo(500, std::vector<int>(500));
int dp(int n) {
    memo[0][0] = v[0][0];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0)
                memo[i][j] = memo[i - 1][j] + v[i][j];
            else if (j == i)
                memo[i][j] = memo[i - 1][j - 1] + v[i][j];
            else
                memo[i][j] =
                    std::max(memo[i - 1][j - 1], memo[i - 1][j]) + v[i][j];
        }
    }
    int max = 0;
    for (int i = 0; i < memo[n - 1].size(); ++i) {
        if (memo[n - 1][i] > max) max = memo[n - 1][i];
    }
    return max;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            std::cin >> v[i][j];
        }
    }
    std::cout << dp(N);
    return 0;
}