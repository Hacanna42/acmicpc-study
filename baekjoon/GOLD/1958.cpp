// 백준: LCS 3
// https://www.acmicpc.net/problem/1958
// 2024-06-09

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b, c;
    cin >> a >> b >> c;
    vector<vector<vector<int>>> dp(a.length() + 1, vector<vector<int>>(b.length() + 1, vector<int>(c.length() + 1, 0)));
    for (int i = 1; i <= a.length(); ++i) {
        for (int j = 1; j <= b.length(); ++j) {
            for (int k = 1; k <= c.length(); ++k) {
                if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1]) { // 공통 문자
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;      // 이전 문자열에서 +1
                } else {
                    dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]}); // 이전 문자열에서 제일 큰 것 계승
                }
            }
        }
    }

    /*
    // 연습용 역추적
    string lcs;
    int al = a.length();
    int bl = b.length();
    int cl = c.length();

    while (al > 0 && bl > 0 && cl > 0) {
        if (dp[al][bl][cl] == dp[al - 1][bl][cl])
            al--;
        else if (dp[al][bl][cl] == dp[al][bl - 1][cl])
            bl--;
        else if (dp[al][bl][cl] == dp[al][bl][cl - 1])
            cl--;
        else {
            lcs.push_back(a[al - 1]);
            al--;
            bl--;
            cl--;
        }
    }

    reverse(lcs.begin(), lcs.end());
    cout << lcs << endl;

*/

    cout << dp[a.length()][b.length()][c.length()];
    return 0;
}