// 백준: 파스칼의 삼각형
// https://www.acmicpc.net/problem/16395
// 2024-03-28
// 오랜만

#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    int N, K;
    cin >> N >> K; // N번째층의 K수 구하기
    // DP 문제
    // dp[i][j] = i층에서의 j번째 수
    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, 0));
    // BASE CASE
    dp[1][1] = 1;
    if (N >= 2)
        dp[2][1] = 1;
    if (N >= 2)
        dp[2][2] = 1;

    for (int i = 3; i <= N; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (j == 1)
                dp[i][j] = dp[i - 1][j];
            else if (j == i)
                dp[i][j] = dp[i - 1][j - 1];
            else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }

    cout << dp[N][K];
    return 0;
}