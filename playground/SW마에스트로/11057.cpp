#include <iostream>
#include <vector>
using namespace std;
#define MOD 10007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    vector<vector<int>> dp(N + 1, vector<int>(10));

    // BASE CASE
    for (int i = 0; i <= 9; ++i) {
        dp[1][i] = 1;
    }

    // UPDATE
    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k <= j; ++k) {
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= MOD;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i <= 9; ++i) {
        answer += dp[N][i] % MOD;
    }
    cout << answer % MOD;
    return 0;
}