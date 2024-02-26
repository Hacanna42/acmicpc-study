#include <iostream>
#include <vector>
#define MOD 1'000'000'000
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<vector<ll>> dp(K + 1, vector<ll>(N + 1, 0));
    for (int i = 0; i <= N; ++i) {
        dp[1][i] = 1;
    }
    // dp[K][N] = c | K개의 수로 N을 만드는 경우 c
    // dp[K][N] = dp[K-1][N] + dp[K-1][N-1] + dp[K-1][N-2]...

    for (int i = 2; i <= K; ++i) {
        for (int j = 0; j <= N; ++j) {
            for (int k = 0; k <= j; ++k) {
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= MOD;
            }
        }
    }

    cout << dp[K][N];
    return 0;
}