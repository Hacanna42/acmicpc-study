// 백준: 이친수
// https://www.acmicpc.net/problem/2193
// 2024-04-02

#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<vector<ll>> dp(N + 1, vector<ll>(2));

    // BASE CASE
    dp[1][0] = 0;
    dp[1][1] = 1;

    if (N >= 2)
        dp[2][0] = 1;
    if (N >= 2)
        dp[2][1] = 0;

    for (int i = 3; i <= N; ++i) {
        dp[i][0] = dp[i - 1][1] + dp[i - 1][0];
        dp[i][1] = dp[i - 1][0];
    }

    cout << dp[N][0] + dp[N][1];
    return 0;
}