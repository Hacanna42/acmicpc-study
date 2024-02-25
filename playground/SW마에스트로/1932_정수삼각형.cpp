#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> pascal(N, vector<int>(N)); // 층, 인덱스
    vector<vector<int>> dp(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> pascal[i][j];
        }
    }

    // BASE CASE
    if (N >= 1)
        dp[0][0] = pascal[0][0];
    if (N >= 2)
        dp[1][0] = pascal[0][0] + pascal[1][0];
    if (N >= 3)
        dp[1][1] = pascal[0][0] + pascal[1][1];

    for (int i = 2; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            // EDGE CASE
            if (j == 0)
                dp[i][j] = dp[i - 1][j] + pascal[i][j];
            if (j == i)
                dp[i][j] = dp[i - 1][j - 1] + pascal[i][j];

            else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + pascal[i][j];
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < dp[N - 1].size(); ++i) {
        answer = max(answer, dp[N - 1][i]);
    }

    cout << answer;

    return 0;
}