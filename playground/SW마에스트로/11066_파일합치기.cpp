#include <algorithm>
#include <iostream>
#include <vector>
#define INF (~0U >> 2)
using namespace std;
int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int page_num;
        cin >> page_num;
        vector<int> sum(page_num + 1, 0);
        vector<int> files(page_num + 1, 0);
        for (int i = 1; i <= page_num; ++i) {
            cin >> files[i];
            sum[i] = sum[i - 1] + files[i];
        }

        vector<vector<int>> dp(page_num + 1, vector<int>(page_num + 1));

        for (int i = 1; i <= page_num; ++i) {         // range
            for (int j = 1; j <= page_num - i; ++j) { // start index
                dp[j][j + i] = INF;
                for (int k = j; k < i + j; ++k) { // split point
                    dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][i + j] + sum[i + j] - sum[j - 1]);
                }
            }
        }

        cout << dp[1][page_num] << "\n";
    }
    return 0;
}