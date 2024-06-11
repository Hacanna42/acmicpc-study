// 백준: LCS 2
// https://www.acmicpc.net/problem/9252
// 2024-06-09
// 복습

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));
    for (int i = 1; i <= a.length(); ++i) {
        for (int j = 1; j <= b.length(); ++j) {
            if (a[i - 1] == b[j - 1]) {          // 문자열이 같으면
                dp[i][j] = dp[i - 1][j - 1] + 1; // 이전 문자열 + 1
            } else {                             // 문자열이 다르면 이전 문자열 중 큰 것
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    int n = a.length();
    int m = b.length();

    cout << dp[n][m] << "\n";

    string lcs; // 역추적
    while (n > 0 && m > 0) {
        if (dp[n][m] == dp[n - 1][m]) { // 같은 값이 있으면 그쪽으로 진행
            n--;
        } else if (dp[n][m] == dp[n][m - 1]) {
            m--;
        } else {
            lcs.push_back(a[n - 1]); // 같은 값이 없으면 if a[i - 1] == b[j - 1], dp[i][j] = dp[i - 1][j - 1] + 1; 이 된것임으로 LCS로 선택됨
            n--;
            m--;
        }
    }

    reverse(lcs.begin(), lcs.end());
    if (lcs.size() != 0)
        cout << lcs;
    return 0;
}