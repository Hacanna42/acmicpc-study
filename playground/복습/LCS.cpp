// LCS 복습
// 2024-06-14

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int al = a.length();
    int bl = b.length();
    vector<vector<int>> dp(al + 1, vector<int>(bl + 1, 0));
    for (int i = 1; i <= al; ++i) {
        for (int j = 1; j <= bl; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[al][bl];

    // 역추적

    string LCS;
    while (al > 0 && bl > 0) {
        if (a[al - 1] == b[bl - 1]) { // 같으면
            LCS.push_back(a[al - 1]);
            al--;
            bl--;
        } else if (dp[al][bl] == dp[al - 1][bl]) // 같은 값이 있으면 그쪽으로 진행
            al--;
        else if (dp[al][bl] == dp[al][bl - 1])
            bl--;
    }

    reverse(LCS.begin(), LCS.end());
    cout << LCS;
    return 0;
}