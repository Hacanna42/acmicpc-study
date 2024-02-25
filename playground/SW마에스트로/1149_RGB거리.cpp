// 백준: RGB거리
// https://www.acmicpc.net/problem/1149
// 2024-02-24
// 소마 대비

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    vector<vector<int>> dp(N + 1, vector<int>(3));
    vector<vector<int>> prices(N + 1, vector<int>(3));
    for (int i = 1; i <= N; ++i) {
        cin >> prices[i][0] >> prices[i][1] >> prices[i][2];
    }

    /*
    1번 집의 색은 2번 집의 색과 같지 않아야 한다.
    N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
    i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.
    */

    // RGB
    // 0 현재 집을 R로 색칠
    // 1 현재 집을 G로 색칠
    // 2 현재 집을 B로 색칠

    dp[1][0] = prices[1][0];
    dp[1][1] = prices[1][1];
    dp[1][2] = prices[1][2];

    for (int i = 2; i <= N; ++i) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + prices[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + prices[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + prices[i][2];
    }

    cout << min({dp[N][0], dp[N][1], dp[N][2]});

    return 0;
}