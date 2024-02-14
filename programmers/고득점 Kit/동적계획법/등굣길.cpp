#include <string>
#include <vector>

using namespace std;
#define MOD 1'000'000'007

int solution(int m, int n, vector<vector<int>> puddles) {
    /*
    dp[i][j] 는 (i, j) 까지 도달할 수 있는 경로의 수.
    시작점 : (1, 1) 도착 : (M, N)
    */
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[1][1] = 1;

    for (int i = 0; i < puddles.size(); ++i) {
        dp[puddles[i][0]][puddles[i][1]] = -1;
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dp[i][j] == -1) {
                dp[i][j] = 0;
                continue; // 물 웅덩이 무빙
            }
            if (i > 1)
                dp[i][j] += dp[i - 1][j] % MOD;
            if (j > 1)
                dp[i][j] += dp[i][j - 1] % MOD;
            dp[i][j] %= MOD;
        }
    }
    return dp[m][n];
}