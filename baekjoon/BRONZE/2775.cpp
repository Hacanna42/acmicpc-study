// 백준: 부녀회장이 될테야
// https://www.acmicpc.net/problem/2775
// 2024-04-23

#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int k; // 층
        int n; // 호
        cin >> k >> n;
        vector<vector<ll>> dp(k + 1, vector<ll>(n + 1));
        // BASE CASE
        for (int i = 1; i <= n; ++i) {
            dp[0][i] = i; // 0층의 i호에는 i명이 산다 *
        }

        for (int h = 1; h <= k; ++h) {     // 층 루프
            for (int w = 1; w <= n; ++w) { // 호 루프
                // 현재 층에서 가리키고 있는 호에 대해서 0까지 이전 층에서 루프
                for (int i = w; i > 0; --i) {
                    dp[h][w] += dp[h - 1][i];
                }
            }
        }

        cout << dp[k][n] << "\n";
    }
    return 0;
}