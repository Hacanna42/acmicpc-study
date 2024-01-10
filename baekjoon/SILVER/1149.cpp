// 백준: RGB거리
// https://www.acmicpc.net/problem/1149
// 2024-01-10

/*
dp[i][색] 을 i번째 집까지 칠했을때의 최소 비용이라고 할 때,
dp[i-1][다른 색들] + i번째 집을 칠하는 비용 이라고 할 수 있음
*/
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int> > v;
std::vector<std::vector<int> > memo;

int dp(int n) {
    memo[0][0] = v[0][0];
    memo[0][1] = v[0][1];
    memo[0][2] = v[0][2];

    for (int i = 1; i < n; ++i) {
        memo[i][0] = std::min(memo[i - 1][1], memo[i - 1][2]) + v[i][0];
        memo[i][1] = std::min(memo[i - 1][0], memo[i - 1][2]) + v[i][1];
        memo[i][2] = std::min(memo[i - 1][0], memo[i - 1][1]) + v[i][2];
    }
    return std::min({memo[n - 1][0], memo[n - 1][1], memo[n - 1][2]});
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N;
    std::cin >> N;
    v.assign(N, std::vector<int>(N));
    memo.assign(N, std::vector<int>(N));
    for (int i = 0; i < N; ++i) {
        std::cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    std::cout << dp(N);
    return 0;
}