#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int TC = 0;
    cin >> TC;
    for (int i = 0; i < TC; ++i) {
        int N;
        cin >> N;
        vector<int> dp(N + 1);
        if (N >= 1)
            dp[1] = 1;
        if (N >= 2)
            dp[2] = 2;
        if (N >= 3)
            dp[3] = 4;
        for (int j = 4; j <= N; ++j) {
            dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
        }
        cout << dp[N] << "\n";
    }
    return 0;
}