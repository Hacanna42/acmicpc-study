// 백준: RGB거리 2
// https://www.acmicpc.net/problem/17404
// 2024-06-18

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; // 집의 수
    cin >> N;
    vector<vector<int>> prices(N, vector<int>(3));
    /*
    0. R
    1. G
    2. B
    */
    for (int i = 0; i < N; ++i) { // 0-based index
        int R, G, B;              // 각 비용
        cin >> R >> G >> B;
        prices[i][0] = R;
        prices[i][1] = G;
        prices[i][2] = B;
    }
    // dp[i][c][s] = k
    // 첫 집을 s로 칠하고, i번째 집을 c로 칠한 값까지 고려했을때의 최댓값 k
    vector<vector<vector<int>>> dp(N, vector<vector<int>>(3, vector<int>(3, (~0U >> 2))));
    /* BASE CASE
        dp[0][0][0] = 첫번째 집을 RED로 칠하는 비용
        dp[0][1][1] = 첫번째 집을 GREEN으로 칠하는 비용
        dp[0][2][2] = 첫번째 집을 BLUE로 칠하는 비용
    */
    for (int i = 0; i < 3; ++i) {
        dp[0][i][i] = prices[0][i];
    }

    // 일단 첫번째 집을 어떤 색으로 칠했느냐에 따라 분기를 나눠야 한다.
    for (int st = 0; st < 3; ++st) {
        for (int i = 1; i < N; ++i) {
            dp[i][0][st] = min(dp[i - 1][1][st], dp[i - 1][2][st]) + prices[i][0];
            dp[i][1][st] = min(dp[i - 1][0][st], dp[i - 1][2][st]) + prices[i][1];
            dp[i][2][st] = min(dp[i - 1][0][st], dp[i - 1][1][st]) + prices[i][2];
        }
    }

    int min_price = (~0U >> 2);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j)
                continue;
            min_price = min(min_price, dp[N - 1][i][j]);
        }
    }

    cout << min_price;

    return 0;
}