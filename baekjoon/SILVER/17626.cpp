// 백준: Four Squares
// https://www.acmicpc.net/problem/17626
// 2024-04-28

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> dp(N + 1, 0);
    for (int i = 0; i <= N; ++i) {
        dp[i] = i;
    }

    // BASE CASE
    dp[0] = 0;
    if (N >= 1)
        dp[1] = 1;
    if (N >= 2)
        dp[2] = 2;
    if (N >= 3)
        dp[3] = 3;
    if (N >= 4)
        dp[4] = 1;

    for (int i = 5; i <= N; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            dp[i] = min(dp[i], dp[i - (j * j)] + 1);
        }
    }

    cout << dp[N];
    return 0;
}