#include <iostream>
#include <vector>
#define MOD 1'000'000'000
using namespace std;
typedef long long ll;

// dp[i][j] : 길이 i에서 j로 끝나는 계단 수

int main() {
    int N;
    cin >> N;
    vector<vector<ll>> dp(N + 1, vector<ll>(10));

    dp[1][0] = 0;
    for (int i = 1; i <= 9; ++i) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j <= 9; ++j) {
            if (j != 0 && j != 9)
                dp[i][j] = dp[i - 1][j - 1] % MOD + dp[i - 1][j + 1] % MOD;
            else if (j == 0)
                dp[i][j] = dp[i - 1][j + 1] % MOD;
            else if (j == 9)
                dp[i][j] = dp[i - 1][j - 1] % MOD;
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