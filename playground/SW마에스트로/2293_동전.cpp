#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> coins(n);
    vector<int> dp(k + 1, 0);

    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    dp[0] = 1; // 0원을 만드는 경우 = 아무것도 선택하지 않는 한가지

    for (auto &coin : coins) {
        for (int i = coin; i <= k; ++i) {
            dp[i] += dp[i - coin];
        }
    }

    cout << dp[k];
    return 0;
}
