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
    vector<int> dp(N + 1, 0);
    vector<int> prices(N + 1);
    cin >> prices[1];
    if (N >= 1)
        dp[1] = prices[1];

    for (int i = 2; i <= N; ++i) {
        cin >> prices[i];
    }

    for (int i = 2; i <= N; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] = max(dp[i], dp[i - j] + prices[j]);
        }
    }

    cout << dp[N];
    return 0;
}