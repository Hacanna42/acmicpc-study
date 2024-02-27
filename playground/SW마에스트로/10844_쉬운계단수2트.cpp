#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
#define MOD 1'000'000'000
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    vector<vector<ll>> dp(N + 1, vector<ll>(10, 0));
    for (int i = 1; i <= 9; ++i) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j <= 9; ++j) {
            if (j == 0) {
                dp[i][j] += dp[i - 1][j + 1] % MOD;
            } else if (j == 9) {
                dp[i][j] += dp[i - 1][j - 1] % MOD;
            } else {
                dp[i][j] += dp[i - 1][j - 1] % MOD + dp[i - 1][j + 1] % MOD;
            }
            dp[i][j] %= MOD;
        }
    }

    ll answer = 0;
    for (int i = 0; i <= 9; ++i) {
        answer += dp[N][i];
        answer %= MOD;
    }
    cout << answer;
    return 0;
}